#ifndef SRC_ESP32_COMMANDER_COMMANDER_SETUP_H_
#define SRC_ESP32_COMMANDER_COMMANDER_SETUP_H_
#include <Arduino.h>
#include <Commander.h>
#include "esp32/commander/commander_handler.h"

extern Commander cmd;

/**
 * @brief Initialize Serial Commander
 *
 */
void setup_serial_commander();

/**
 * @brief Intialise Commander
 *
 */
void initialiseCommander();

/**
 * @brief Loop serial commander
 *
 */
void loop_serial_commander();

#endif // SRC_ESP32_COMMANDER_COMMANDER_SETUP_H_
