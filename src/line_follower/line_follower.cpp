#include <Arduino.h>
#include <pins_line_follower.h>
#include "line_follower/line_follower.h"
#include "line_follower/control_direction.h"

const uint8_t line_sensor_count = 3; // Number of line sensors
uint8_t line_sensor_values[line_sensor_count];
uint8_t total_inactive_line_sensor;

/**
 * @brief Activates the line follower mode
 *
 */
void activateLineFollowerMode()
{
  // Get IR sensor position
  int16_t current_position = readLinePosition();

  while (current_position != 0)
  {
    calculatePID(current_position);

    current_position = readLinePosition();
  }

  deactivateLineFollowerMode();
}

/**
 * @brief Deactivate the line follower mode
 *
 */
void deactivateLineFollowerMode()
{
  controlDirection(STOP_SLOW, 0);
}

/**
 * @brief This function calculates the line position error using a PID control algorithm.
 *
 */
void calculatePID(int current_position)
{
  uint8_t base_speed = 200;
  uint8_t max_speed = 255;
  float Kp = 0.38;
  float Kd = 0;
  static int16_t last_error = 0;

  // Calculate the error as the difference between the desired position (1000) and the current position
  int16_t error = 1000 - current_position;

  // Set the motor speed based on proportional, integral, and derivative PID terms.
  float pid = Kp * error + Kd * (error - last_error);

  // Record the current error for the next iteration
  last_error = error;

  // Adjust the speed of the motors based on the PID control signal
  uint8_t motor_left_speed = constrain(base_speed - pid, 0, max_speed);
  uint8_t motor_right_speed = constrain(base_speed + pid, 0, max_speed);

  // If the line is not detected by any sensor, turn tight to to last known position
  /*   if (total_inactive_line_sensor == line_sensor_count && current_position != 1000)
    {
      restorePosition(motor_left_speed, motor_right_speed);
      return;
    } */

  analogWrite(MOTOR_LEFT_FORWARD_PIN, motor_left_speed);
  digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_RIGHT_FORWARD_PIN, motor_right_speed);
  digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);

  // SerialPrintPosition(current_position, motor_left_speed, motor_right_speed);
}

/**
 * Out of line. Turn back to the last known position
 *
 */
void restorePosition(uint8_t motor_left_speed, uint8_t motor_right_speed)
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
  unsigned long interval = 1;
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

  total_inactive_line_sensor = line_sensor_values[0] + line_sensor_values[1] + line_sensor_values[2];

  // Finish line, all sensors detect the black line
  if (total_inactive_line_sensor == 0)
  {
    return 0;
  }

  uint16_t position = (2000 * line_sensor_values[2] + 1000 * line_sensor_values[1] +
                       0 * line_sensor_values[0]) /
                      total_inactive_line_sensor;

  // Remembers where the sensor saw the line,
  // so if you ever lose the line to the left or the right,
  // its line position will continue to indicate the direction
  // you need to go to reacquire the line

  if (total_inactive_line_sensor == line_sensor_count)
  {
    position = last_position;
  }

  last_position = position;

  return position;
}

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(uint16_t current_position, uint8_t motor_left_speed, uint8_t motor_right_speed)
{
  for (int i = 0; i < line_sensor_count; i++)
  {
    Serial.print(line_sensor_values[i]);
    Serial.print("\t");
  }

  Serial.print(current_position);
  Serial.print("\t");

  Serial.print(motor_left_speed);
  Serial.print("\t");

  Serial.print(motor_right_speed);
  Serial.print("\t");
  Serial.println();
  delay(1500);
}
