#include <Arduino.h>
#include <pins_line_follower.h>
#include "line_follower/control_direction.h"

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-100, with max speed 100)
 * @param period Running period in ms (-1 for infinite period, or period > 0)
 */
void controlDirection(uint8_t direction, uint8_t speed = 255, int16_t period = 1000)
{
  uint32_t start_time = millis();
  uint32_t current_time = start_time;

  // Map the speed value to a range of 0-100
  uint8_t mapSpeed = map(speed, 0, 100, 0, 255);

  // Check if the period is infinite (negative or zero)
  bool is_infinite = (period <= 0);

  // loop for entire period
  while (is_infinite || current_time - start_time < abs(period))
  {
    switch (direction)
    {
    // FORWARD
    case FORWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    // BACKWARD
    case BACKWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, mapSpeed);
      break;
    // RIGHT WIDE FORWARD
    case RIGHT_WIDE_FORWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    // RIGHT TIGHT FORWARD
    case RIGHT_TIGHT_FORWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    // RIGHT WIDE BACKWARD
    case RIGHT_WIDE_BACKWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, mapSpeed);
      break;
    // LEFT WIDE FORWARD
    case LEFT_WIDE_FORWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    // LEFT RIGHT FORWARD
    case LEFT_TIGHT_FORWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, mapSpeed);
      break;
      // LEFT WIDE BACKWARD
    case LEFT_WIDE_BACKWARD:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    // STOP FAST
    case STOP_FAST:
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, mapSpeed);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, mapSpeed);
      break;
    default:
      // STOP SLOW
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      break;
    }

    // Update current time
    current_time = millis();
  }

  // Stop the motors after the specified period
  analogWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
  analogWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  analogWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
  analogWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
}
