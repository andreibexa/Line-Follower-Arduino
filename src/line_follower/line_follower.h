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
 * ? Should I disable more pins
 */
void deactivateLineFollowerMode();

#endif // SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
