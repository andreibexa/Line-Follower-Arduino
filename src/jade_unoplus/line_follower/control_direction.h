#ifndef JADE_UNOPLUS_LINE_FOLLOWER_CONTROL_DIRECTION_H_
#define JADE_UNOPLUS_LINE_FOLLOWER_CONTROL_DIRECTION_H_

#include "serial_transfer/enum_direction.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

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
