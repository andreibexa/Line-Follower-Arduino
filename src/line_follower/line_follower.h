#ifndef SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_

#include <Arduino.h>
#include <pins_line_follower.h>

/**
 * @brief Initialize Line follower
 *
 */
void activateLineFollowerMode();

/**
 * @brief Disable the Line follower mode
 * ? Should I disable more pins
 */
void deactivateLineFollowerMode();

/**
 * @brief Set the pin value of IR Infrared sensors to LOW or HIGH
 *
 * @param val The pin value (LOW or HIGH).
 */
void setIrInfraredSensors(uint8_t val);

#endif // SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
