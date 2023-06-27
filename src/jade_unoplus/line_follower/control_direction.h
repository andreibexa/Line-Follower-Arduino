#ifndef JADE_UNOPLUS_LINE_FOLLOWER_CONTROL_DIRECTION_H_
#define JADE_UNOPLUS_LINE_FOLLOWER_CONTROL_DIRECTION_H_

#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

// Enumeration for different directions
enum Direction {
  STOP_SLOW,            // Stop slowly
  STOP_FAST,            // Stop quickly
  FORWARD,              // Move forward
  BACKWARD,             // Move backward
  RIGHT_WIDE_FORWARD,   // Turn right with wide angle forward
  RIGHT_TIGHT_FORWARD,  // Turn right with tight angle forward
  RIGHT_WIDE_BACKWARD,  // Turn right with wide angle backward
  LEFT_WIDE_FORWARD,    // Turn left with wide angle forward
  LEFT_TIGHT_FORWARD,   // Turn left with tight angle forward
  LEFT_WIDE_BACKWARD,   // Turn left with wide angle backward
};

/**
 * @brief Control the direction and speed of both wheels for a specific period
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 * @param runTime Running period in ms. Default 1000ms
 */
void temporizedDirection(uint8_t direction, uint8_t speed, int16_t runTime);

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-255)
 *
 */
void setDirection(uint8_t direction, uint8_t speed);

#endif  // JADE_UNOPLUS_LINE_FOLLOWER_CONTROL_DIRECTION_H_
