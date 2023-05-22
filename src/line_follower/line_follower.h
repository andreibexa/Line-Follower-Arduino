#ifndef SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_

#include <Arduino.h>
#include <pins_line_follower.h>

/**
 * @brief Activate line follower mode
 *
 */
void activateLineFollowerMode();

/**
 * @brief Disable the Line follower mode
 *
 */
void deactivateLineFollowerMode();

/**
 * @brief Reads the line position using QTR sensors and returns the calibrated position value.
 *
 * @return The line position value
 */
uint16_t readLinePosition();

#endif // SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
