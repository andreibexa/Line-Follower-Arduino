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
  static int last_error = 0;

  // Define PID constants
  const double Kp = 0.26;
  const double Kd = 0;

  // Compute our "error" from the line position. We will make it so that the
  // error is zero when the middle sensor is over the line, because this is our
  // goal. Error will range from 1500 to 2500. If we have sensor 1500 on the left
  // and sensor 2 on the right, a reading of 1500 means that we see the line on
  // the left and a reading of 2500 means we see the line on the right.
  int16_t error = 2000 - readLinePosition();

  // Set the motor speed based on proportional and derivative PID terms:
  // KP is the floating-point proportional constant (maybe start with a value around 0.1)
  // KD is the floating-point derivative constant (maybe start with a value around 5)
  // Note that when doing PID, it is very important you get your signs right, or
  // else the control loop will be unstable.
  int16_t pid = Kp * error + Kd * (error - last_error);
  last_error = error;

  // Adjust the speed of the motors based on the PID control signal
  int16_t motor_right_speed = constrain(190 - pid, 0, 190);
  int16_t motor_left_speed = constrain(190 + pid, 0, 190);

  analogWrite(MOTOR_RIGHT_FORWARD_PIN, motor_right_speed);
  analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_LEFT_FORWARD_PIN, motor_left_speed);
  analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);

  /*   for (uint8_t i = 0; i < QTR_SENSOR_COUNT; i++)
    {
      Serial.print(QTR_SENSOR_VALUES[i]);
      Serial.print('\t');
    }

    Serial.print(readLinePosition());
    Serial.print('\t');

    Serial.print('\t');
    Serial.print(motor_left_speed);
    Serial.print('\t');
    Serial.print(motor_right_speed);
    Serial.println();
    delay(1000); */
}

/**
 * @brief Reads the line position using QTR sensors and returns the calibrated position value.
 *
 * @return The line position value
 */
uint16_t readLinePosition()
{
  static int last_position = 2000;
  uint16_t total_qtr_sensor_values = 0;

  // Get calibrated sensor values returned in the sensors array,
  // along with the line position.
  // position will range from 1500 to 2500, with 2000 corresponding
  // to the line over the middle sensor
  uint16_t position = qtr.readLineBlack(QTR_SENSOR_VALUES);

  // Get sum of qtr sensor values
  for (uint8_t i = 0; i < QTR_SENSOR_COUNT; i++)
  {
    total_qtr_sensor_values += QTR_SENSOR_VALUES[i];
  }

  // Remembers where the sensor saw the line,
  // so if you ever lose the line to the left or the right,
  // its line position will continue to indicate the direction
  // you need to go to reacquire the line, even the path background is not white
  if (total_qtr_sensor_values >= 4900)
  {
    position = last_position;
  }
  else
  {
    last_position = position;
  }

  return position;
}

/**
 * @brief Disable the Line follower mode
 * ? Should i disable more pins
 */
void deactivateLineFollowerMode()
{
  // !TODO(my_username): call motorStopFunction()
}
