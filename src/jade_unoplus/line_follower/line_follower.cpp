#include <Arduino.h>
#include <pins_jade_unoplus.h>
#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/line_follower/control_direction.h"
#include "jade_unoplus/obstacle_detector/obstacle_detector.h"
#include "jade_unoplus/eeprom_data/eeprom_data.h"

uint8_t const line_sensor_count = 3; // Number of line sensors
uint8_t line_sensor_values[line_sensor_count];
uint8_t num_non_detected_line_sensor;

/**
 * @brief Enable the Line Follower mode
 *
 */
void enableLineFollowerMode()
{
  int16_t current_position = readLinePosition();

  // loop while reading the line
  do
  {
    // Avoid obstacle closer than 30 cm
    avoidObstacle(30);

    // Get IR sensor position
    current_position = readLinePosition();

    // Follow the line
    calculatePID(current_position);

  } while (current_position != 0);

  disableLineFollowerMode();
}

/**
 * @brief Disable the Line Follower mode
 *
 */
void disableLineFollowerMode()
{
  setDirection(STOP_SLOW, 0);
}

/**
 * @brief This function calculates the line position error using a PID control algorithm.
 *
 */
void calculatePID(uint16_t current_position)
{
  uint8_t min_speed = eeprom_settings.min_speed;
  uint8_t base_speed = eeprom_settings.base_speed;
  uint8_t max_speed = eeprom_settings.max_speed;

  // adjust Kp to get the best results for the line follower
  float Kp = eeprom_settings.kp;
  float Kd = 0;
  static int16_t last_error = 0;

  // Calculate the error as the difference between the desired position (1000) and the current position
  int16_t error = 1000 - current_position;

  // Set the motor speed based on proportional, integral, and derivative PID terms.
  float pid = Kp * error + Kd * (error - last_error);

  // Record the current error for the next iteration
  last_error = error;

  // Calculate the motor speeds based on the PID control signal
  int16_t motor_left_speed = constrain(base_speed - pid, min_speed, max_speed);
  int16_t motor_right_speed = constrain(base_speed + pid, min_speed, max_speed);

  analogWrite(MOTOR_LEFT_FORWARD_PIN, motor_left_speed);
  digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_RIGHT_FORWARD_PIN, motor_right_speed);
  digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);

  // If the line is not detected by any sensor, turn tight to to last known position
  /*   if (num_non_detected_line_sensor == line_sensor_count && current_position != 1000)
    {
      restorePosition(motor_left_speed, motor_right_speed);
      return;
    }
   */

  // SerialPrintPosition(current_position, motor_left_speed, motor_right_speed);
}

/**
 * Out of line. Turn back to the last known position
 *
 */
void restorePosition(int16_t motor_left_speed, int16_t motor_right_speed)
{
  if (motor_left_speed > motor_right_speed)
  {
    // RIGHT_TIGHT_FORWARD
    analogWrite(MOTOR_LEFT_FORWARD_PIN, motor_left_speed);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, 1);
  }
  else if (motor_left_speed < motor_right_speed)
  {
    // LEFT_TIGHT_FORWARD
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, 1);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, motor_right_speed);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  }
}

/**
 * @brief Reads the line position using the IR sensors.
 * The returned value will range from 0 to 1500, with 1000 corresponding to
 * a position under the middle sensor.
 * @return Position value (500, 1000, 1500)
 */
uint16_t readLinePosition()
{
  // Read the IR sensors each 2500 micro seconds
  unsigned long interval = 2500;
  static unsigned long previousTime = 0;
  unsigned long currentTime = micros();

  if (currentTime - previousTime >= interval)
  {
    line_sensor_values[0] = digitalRead(IR_TRACKING_SENSOR_RIGHT_PIN);
    line_sensor_values[1] = digitalRead(IR_TRACKING_SENSOR_CENTER_PIN);
    line_sensor_values[2] = digitalRead(IR_TRACKING_SENSOR_LEFT_PIN);

    previousTime = currentTime;
  }

  static int last_position = 1000; // line in the center

  // Get calibrated sensor values returned in the sensors array,
  // along with the line position.
  // position will range from 1500 to 3000, with 1500 corresponding
  // to the line over the middle sensor

  num_non_detected_line_sensor = line_sensor_values[0] + line_sensor_values[1] + line_sensor_values[2];

  // The finish line, all sensors detect the black line
  if (num_non_detected_line_sensor == 0)
  {
    return 0;
  }

  uint16_t position = (2000 * line_sensor_values[2] + 1000 * line_sensor_values[1] +
                       0 * line_sensor_values[0]) /
                      num_non_detected_line_sensor;

  // Remembers where the sensor saw the line,
  // so if you ever lose the line to the left or the right,
  // its line position will continue to indicate the direction
  // you need to go to reacquire the line

  if (num_non_detected_line_sensor == line_sensor_count)
  {
    position = last_position;
  }

  last_position = position;

  return position;
}

/**
 * @brief Avoid obstacle
 *
 * @param min_obstacle_distance Avoid obstacle if the distance is less than min_obstacle_distance
 */
void avoidObstacle(uint8_t min_obstacle_distance)
{
  uint16_t current_position;

  if (getDistance() < min_obstacle_distance)
  {
    // Stop if obstacle is detected
    setDirection(STOP_FAST, 255);
    delay(800);

    current_position = readLinePosition();
    // Turn right till the left IR sensor is under the line
    while (current_position != 500)
    {
      setDirection(RIGHT_TIGHT_FORWARD, 200);
      current_position = readLinePosition();
    }

    // Turn right
    setDirection(RIGHT_WIDE_FORWARD, 200);
    delay(100);

    // Forward at 45 degree
    setDirection(FORWARD, 255);
    delay(900);

    // Turn left
    setDirection(LEFT_WIDE_FORWARD, 200);
    delay(700);

    readLinePosition();
    // Go forward at 45 degree
    while (num_non_detected_line_sensor == line_sensor_count)
    {
      setDirection(FORWARD, 255);

      // Refresh num_non_detected_line_sensor
      readLinePosition();
    }

    // Stop if the line is detected
    setDirection(STOP_FAST, 255);
    delay(800);
  }
}

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(uint16_t current_position, int16_t motor_left_speed, int16_t motor_right_speed)
{
  for (int i = 0; i < line_sensor_count; i++)
  {
    Serial.print(line_sensor_values[i]);
    Serial.print("\t");
  }

  Serial.print(current_position);
  Serial.print("\t");

  Serial.print(num_non_detected_line_sensor);
  Serial.print("\t");

  Serial.print(motor_left_speed);
  Serial.print("\t");

  Serial.print(motor_right_speed);
  Serial.print("\t");
  Serial.println();
  delay(1500);
}
