#include <Arduino.h>
#include <pins_jade_unoplus.h>
#include "jade_unoplus/line_follower/control_direction.h"

/**
 * @brief Control the direction and speed of both wheels for a specific period
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 * @param runTime Running period in ms. Default 1000ms
 */
void temporizedDirection(uint8_t direction, uint8_t speed, int16_t runTime = 1000)
{
  static uint32_t start_time = millis();
  uint32_t current_time = millis();

  speed = constrain(speed, 0, 255);

  while (current_time - start_time < abs(runTime))
  {
    setDirection(direction, speed);

    if (runTime == 0)
    {
      break;
    }

    // Update current time
    current_time = millis();
  }
}

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 *
 */
void setDirection(uint8_t direction, uint8_t speed)
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
    analogWrite(MOTOR_RIGHT_BACKWARD_PIN, speed);
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
    analogWrite(MOTOR_LEFT_BACKWARD_PIN, speed);
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
    digitalWrite(MOTOR_LEFT_FORWARD_PIN, HIGH);
    digitalWrite(MOTOR_LEFT_BACKWARD_PIN, HIGH);
    digitalWrite(MOTOR_RIGHT_FORWARD_PIN, HIGH);
    digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, HIGH);
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
