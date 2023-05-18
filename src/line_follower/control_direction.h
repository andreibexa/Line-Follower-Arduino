#ifndef SRC_LINE_FOLLOWER_CONTROL_DIRECTION_H_
#define SRC_LINE_FOLLOWER_CONTROL_DIRECTION_H_

// Enumeration for different directions
enum Direction
{
  STOP_SLOW,           // Stop slowly
  STOP_FAST,           // Stop quickly
  FORWARD,             // Move forward
  BACKWARD,            // Move backward
  RIGHT_WIDE_FORWARD,  // Turn right with wide angle forward
  RIGHT_TIGHT_FORWARD, // Turn right with tight angle forward
  RIGHT_WIDE_BACKWARD, // Turn right with wide angle backward
  LEFT_WIDE_FORWARD,   // Turn left with wide angle forward
  LEFT_TIGHT_FORWARD,  // Turn left with tight angle forward
  LEFT_WIDE_BACKWARD,  // Turn left with wide angle backward
};

/**
 * @brief Control the direction and speed of both wheels
 *
 * @param direction Movement direction
 * @param speed Movement speed (0-100, with max speed 100)
 * @param period Running period in ms (-1 for infinite period, or period > 0)
 */
void controlDirection(uint8_t direction, uint8_t speed, int16_t period);

#endif // SRC_LINE_FOLLOWER_CONTROL_DIRECTION_H_
