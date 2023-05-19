#include <Arduino.h>
#include <pins_line_follower.h>
#include "line_follower/qtr_sensor/qtr_sensor.h"
#include "line_follower/line_follower.h"
#include "line_follower/control_direction.h"

/**
 * @brief Activates the line follower mode and adjusts the motor direction and
 * speed based on line position.
 * This function reads the calibrated sensor values and calculates
 * the line position error using a PID control algorithm.
 *
 */
void activateLineFollowerMode()
{
  // Define PID constants
  const double Kp = 0.61;
  const double Kd = 0;

  static int last_error = 0;

  // read calibrated sensor values and obtain a measure of the line position
  // from 0 to 5000 (for a white line, use readLineWhite() instead)
  int16_t position = qtr.readLineWhite(QTR_SENSOR_VALUES);

  // Compute our "error" from the line position. We will make it so that the
  // error is zero when the middle sensor is over the line, because this is our
  // goal. Error will range from 1500 to 2500. If we have sensor 1500 on the left
  // and sensor 2 on the right, a reading of 1500 means that we see the line on
  // the left and a reading of 2500 means we see the line on the right.
  int error = position - 500;

  // Set the motor speed based on proportional and derivative PID terms:
  // KP is the floating-point proportional constant (maybe start with a value around 0.1)
  // KD is the floating-point derivative constant (maybe start with a value around 5)
  // Note that when doing PID, it is very important you get your signs right, or
  // else the control loop will be unstable.
  int16_t motor_speed = Kp * error + Kd * (error - last_error);
  last_error = error;

  motor_speed = constrain(motor_speed, -55, 55);

  // Adjust the speed of the motors based on the PID control signal
  int16_t motor_right_speed = 200 + motor_speed;
  int16_t motor_left_speed = 200 - motor_speed;

  analogWrite(MOTOR_RIGHT_FORWARD_PIN, motor_right_speed);
  analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_LEFT_FORWARD_PIN, motor_left_speed);
  analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);

  for (uint8_t i = 0; i < QTR_SENSOR_COUNT; i++)
  {
    Serial.print(QTR_SENSOR_VALUES[i]);
    Serial.print('\t');
  }

  Serial.print(position);
  Serial.print('\t');

  Serial.print('\t');
  Serial.print(motor_left_speed);
  Serial.print('\t');
  Serial.print(motor_right_speed);
  Serial.println();
  delay(1000);
}
/**
 * @brief Disable the Line follower mode
 * ? Should i disable more pins
 */
void deactivateLineFollowerMode()
{
  // !TODO(my_username): call motorStopFunction()
}
