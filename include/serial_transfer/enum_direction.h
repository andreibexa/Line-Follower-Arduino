#ifndef INCLUDE_SERIAL_TRANSFER_ENUM_DIRECTION_H_
#define INCLUDE_SERIAL_TRANSFER_ENUM_DIRECTION_H_

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

#endif  // INCLUDE_SERIAL_TRANSFER_ENUM_DIRECTION_H_
