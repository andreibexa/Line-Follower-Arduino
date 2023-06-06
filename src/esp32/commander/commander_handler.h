#ifndef SRC_ESP32_COMMANDER_COMMANDER_HANDLER_H_
#define SRC_ESP32_COMMANDER_COMMANDER_HANDLER_H_
#include <Commander.h>
#include "esp32/thing_properties/thing_properties.h"

/**
 * @brief Update line_follower_mode cloud variable
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool lineFollowerModeHandler(Commander &Cmdr);

/**
 * @brief Update min_speed cloud variable
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool minSpeedHandler(Commander &Cmdr);

/**
 * @brief Update base_speed cloud variable
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool baseSpeedHandler(Commander &Cmdr);

/**
 * @brief Update max_speed cloud variable
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool maxSpeedHandler(Commander &Cmdr);

/**
 * @brief Update kp cloud variable
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool kpHandler(Commander &Cmdr);

#endif // SRC_ESP32_COMMANDER_COMMANDER_HANDLER_H_
