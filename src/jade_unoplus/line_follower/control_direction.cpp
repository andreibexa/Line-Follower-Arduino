#include "jade_unoplus/line_follower/control_direction.h"

/**
 * @brief Control the direction and speed of both wheels for a specific period
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 * @param runTime Running period in ms. Default 1000ms
 */
void temporizedDirection(uint8_t direction, uint8_t speed, int16_t runTime = 1000) {
  static uint32_t startTime = millis();
  uint32_t currentTime = millis();

  speed = constrain(speed, 0, 255);

  while (currentTime - startTime < abs(runTime)) {
    setDirection(direction, speed);

    if (runTime == 0) {
      break;
    }

    // Update current time
    currentTime = millis();
  }
}

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 *
 */
void setDirection(uint8_t direction, uint8_t speed) {
  speed = constrain(speed, 0, 255);

  uint8_t calibrateLeft = 255;
  uint8_t calibrateRight = 220;
  uint8_t leftSpeed = map(speed, 0, 255, 0, calibrateLeft);
  uint8_t rightSpeed = map(speed, 0, 255, 0, calibrateRight);

  switch (direction) {
    // FORWARD
    case FORWARD:
      analogWrite(MOTOR_LEFT_FORWARD_PIN, leftSpeed);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, rightSpeed);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      break;
    // BACKWARD
    case BACKWARD:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, leftSpeed);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, rightSpeed);
      break;
    // RIGHT WIDE FORWARD
    case RIGHT_WIDE_FORWARD:
      analogWrite(MOTOR_LEFT_FORWARD_PIN, leftSpeed);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      break;
    // RIGHT TIGHT FORWARD
    case RIGHT_TIGHT_FORWARD:
      analogWrite(MOTOR_LEFT_FORWARD_PIN, leftSpeed);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, rightSpeed);
      break;
    // RIGHT WIDE BACKWARD
    case RIGHT_WIDE_BACKWARD:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, leftSpeed);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      break;
    // LEFT WIDE FORWARD
    case LEFT_WIDE_FORWARD:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, rightSpeed);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      break;
    // LEFT TIGHT FORWARD
    case LEFT_TIGHT_FORWARD:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_LEFT_BACKWARD_PIN, leftSpeed);
      analogWrite(MOTOR_RIGHT_FORWARD_PIN, rightSpeed);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
      break;
      // LEFT WIDE BACKWARD
    case LEFT_WIDE_BACKWARD:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      analogWrite(MOTOR_RIGHT_BACKWARD_PIN, rightSpeed);
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
    default:
      digitalWrite(MOTOR_LEFT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_LEFT_BACKWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_FORWARD_PIN, LOW);
      digitalWrite(MOTOR_RIGHT_BACKWARD_PIN, LOW);
  }
}
