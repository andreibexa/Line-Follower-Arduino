#include <Arduino.h>
#include <pins_line_follower.h>
#include "line_follower/control_direction.h"

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-100, with max speed 100)
 * @param period Running period in ms. Default 1000ms
 */
void controlDirection(uint8_t direction, uint8_t speed)
{

  speed = constrain(speed, 0, 255);

  switch (direction)
  {
  // FORWARD
  case FORWARD:
    analogWrite(MOTOR_LEFT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
  // BACKWARD
  case BACKWARD:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, speed);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, speed);
    break;
  // RIGHT WIDE FORWARD
  case RIGHT_WIDE_FORWARD:
    analogWrite(MOTOR_LEFT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
  // RIGHT TIGHT FORWARD
  case RIGHT_TIGHT_FORWARD:
    analogWrite(MOTOR_LEFT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, 1);
    break;
  // RIGHT WIDE BACKWARD
  case RIGHT_WIDE_BACKWARD:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, speed);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
  // LEFT WIDE FORWARD
  case LEFT_WIDE_FORWARD:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
  // LEFT TIGHT FORWARD
  case LEFT_TIGHT_FORWARD:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, 1);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, speed);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
    // LEFT WIDE BACKWARD
  case LEFT_WIDE_BACKWARD:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, speed);
    break;
  // STOP FAST
  case STOP_FAST:
    analogWrite(MOTOR_LEFT_FORWARD_PIN, speed);
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, speed);
    analogWrite(MOTOR_RIGHT_FORWARD_PIN, speed);
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, speed);
    break;
  // STOP SLOW
  case STOP_SLOW:
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
    break;
  }
}
