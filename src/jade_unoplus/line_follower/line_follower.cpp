#include "jade_unoplus/line_follower/line_follower.h"

uint8_t const lineSensorCount = 3;  // Number of line sensors
byte lineSensorValues[lineSensorCount];
uint8_t numDetectedLineSensor;
uint16_t currentPosition;

bool lineFollowerMode;
bool avoidObstacleMode;
int minSpeed;
int baseSpeed;
int maxSpeed;
float kp;

// Initial line follower settings
const bool defaultMode = false;
const bool defaultAvoidObstacleMode = false;
const uint8_t defaultMinSpeed = 0;
const uint8_t defaultBaseSpeed = 180;
const uint8_t defaultMaxSpeed = 255;
float defaultKp = 0.40;

// isRunning is used to avoid running stopLineFollower() in a loop
bool isRunning = false;

// Initialize the line follower settings with default values
void initializeLineFollowerSettings() {
  lineFollowerMode = defaultMode;
  avoidObstacleMode = defaultAvoidObstacleMode;
  minSpeed = defaultMinSpeed;
  baseSpeed = defaultBaseSpeed;
  maxSpeed = defaultMaxSpeed;
  kp = defaultKp;
}

/**
 * @brief Run the Line Follower only if lineFollowerMode is true
 */
void loopLineFollower() {
  if (lineFollowerMode == true) {
    runLineFollower();
  } else {
    stopLineFollower();
  }
}

/**
 * @brief Run the Line Follower
 *
 */
void runLineFollower() {
  if (isRunning == false) {
    // Play a sound when the line follower starts
    playSequence(S_BUTTON_PUSHED);
  }

  isRunning = true;

  // Change the led color to Green
  setMultiColorLed(0, 10, 0, false);

  readLinePosition();

  // Avoid obstacle closer than 30 cm
  if (avoidObstacleMode == true) {
    avoidObstacle(30);
  }

  // Get IR sensor position
  readLinePosition();

  // Calculate error position and follow the line
  calculatePID();

  // Check if finish line is detected
  checkFinishLine();
}

/**
 * @brief Check if finish line is detected
 *
 */
void checkFinishLine() {
  unsigned long currentTime = millis();
  static unsigned long previousTime = 0;

  // Stop the line follower when all sensors detect a horizontal black line.
  // Avoid stopping if crossing an intersection
  if (numDetectedLineSensor == 0 && (currentTime - previousTime) > 200) {
    previousTime = currentTime;
    stopLineFollower();
  }
}

/**
 * @brief Disable the Line Follower
 *
 */
void stopLineFollower() {
  // Avoid running this function in a loop
  if (isRunning == false) {
    return;
  }

  isRunning = false;

  // Stop both motors
  setDirection(STOP_SLOW, 0);

  // Change the led color to Red
  setMultiColorLed(10, 0, 0);

  // Send the lineFollowerMode status to Arduino Cloud
  lineFollowerMode = false;
  transmitLineFollowerSettings();

  playSequence(S_SLEEPING);
}

/**
 * @brief Calculate the line position error using a PID control
 * algorithm.
 *
 */
void calculatePID() {
  // adjust Kp to get the best results for the line follower
  float Kp = kp;
  float Kd = 0;
  static int16_t lastError = 0;

  // Calculate the error as the difference between the desired position (1000)
  // and the current position
  int16_t error = 1000 - currentPosition;

  // Set the motor speed based on proportional, integral, and derivative PID
  // terms.
  float pid = Kp * error + Kd * (error - lastError);

  // Record the current error for the next iteration
  lastError = error;

  // Calculate the motor speeds based on the PID control signal
  int16_t motorLeftSpeed = constrain(baseSpeed - pid, minSpeed, maxSpeed);
  int16_t motorRightSpeed = constrain(baseSpeed + pid, minSpeed, maxSpeed);

  analogWrite(MOTOR_LEFT_FORWARD_PIN, motorLeftSpeed);
  digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_RIGHT_FORWARD_PIN, motorRightSpeed);
  digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);

  // SerialPrintPosition(motorLeftSpeed, motorRightSpeed);
}

/**
 * Out of line. Turn back to the last known position
 *
 * @param motorLeftSpeed
 * @param motorRightSpeed
 *
 */
void restorePosition(int16_t motorLeftSpeed, int16_t motorRightSpeed) {
  if (motorLeftSpeed > motorRightSpeed) {
    // RIGHT_TIGHT_FORWARD
    analogWrite(MOTOR_LEFT_FORWARD_PIN, motorLeftSpeed);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, 1);
  } else if (motorLeftSpeed < motorRightSpeed) {
    // LEFT_TIGHT_FORWARD
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, 1);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, motorRightSpeed);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  }
}

/**
 * @brief Reads the line position using the IR sensors.
 * The returned value will range from 0 to 1500, with 1000 corresponding to
 * a position under the middle sensor.
 *
 */
void readLinePosition() {
  // Read the IR sensors each 2500 micro seconds
  unsigned long interval = 2500;
  static unsigned long previousTime = 0;
  unsigned long currentTime = micros();

  if (currentTime - previousTime >= interval) {
    lineSensorValues[0] = digitalRead(IR_TRACKING_SENSOR_RIGHT_PIN);
    lineSensorValues[1] = digitalRead(IR_TRACKING_SENSOR_CENTER_PIN);
    lineSensorValues[2] = digitalRead(IR_TRACKING_SENSOR_LEFT_PIN);

    previousTime = currentTime;
  }

  static int lastPosition = 1000;  // line in the center

  // Get calibrated sensor values returned in the sensors array,
  // along with the line position.
  // position will range from 1500 to 3000, with 1500 corresponding
  // to the line over the middle sensor

  numDetectedLineSensor =
    lineSensorValues[0] + lineSensorValues[1] + lineSensorValues[2];

  currentPosition =
    (2000 * lineSensorValues[2] + 1000 * lineSensorValues[1] + 0 * lineSensorValues[0])
    / numDetectedLineSensor;

  // Remembers where the sensor saw the line,
  // so if he ever lose the line to the left or the right,
  // currentPosition will continue to indicate a direction
  // to follow

  if (numDetectedLineSensor == lineSensorCount) {
    currentPosition = lastPosition;
  }

  lastPosition = currentPosition;
}

/**
 * @brief Avoids obstacles if the distance to an obstacle is less than the specified minimum distance
 *
 * @param minObstacleDistance The minimum distance threshold for obstacle avoidance
 */
void avoidObstacle(uint8_t minObstacleDistance) {
  if (getDistance() < minObstacleDistance) {
    // Stop if obstacle is detected
    setDirection(STOP_FAST, 255);
    playSequence(S_CONFUSED);
    delay(1500);

    readLinePosition();
    // Turn right till the left IR sensor is under the line
    while (currentPosition != 500) {
      setDirection(RIGHT_TIGHT_FORWARD, 200);
      readLinePosition();
    }

    // Turn right
    setDirection(RIGHT_WIDE_FORWARD, 200);
    delay(100);

    // Go forward at 45 degree
    setDirection(FORWARD, 255);
    delay(900);

    // Turn left
    setDirection(LEFT_WIDE_FORWARD, 200);
    delay(700);

    readLinePosition();
    // Go forward at 45 degree
    while (numDetectedLineSensor == lineSensorCount) {
      setDirection(FORWARD, 255);

      // Refresh numDetectedLineSensor
      readLinePosition();
    }

    // Stop if the line is detected.
    setDirection(STOP_FAST, 255);

    // Don't stop in the intersection
    delay(1900);
  }
}

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(uint16_t motorLeftSpeed, uint16_t motorRightSpeed) {
  for (int i = 0; i < lineSensorCount; i++) {
    Serial.print(lineSensorValues[i]);
    Serial.print("\t");
  }

  Serial.print(currentPosition);
  Serial.print("\t");

  Serial.print(numDetectedLineSensor);
  Serial.print("\t");

  Serial.print(motorLeftSpeed);
  Serial.print("\t");

  Serial.print(motorRightSpeed);
  Serial.print("\t");
  Serial.println();
  delay(1500);
}
