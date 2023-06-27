#ifndef JADE_UNOPLUS_SYSTEM_STATUS_BATTERY_VOLTAGE_H_
#define JADE_UNOPLUS_SYSTEM_STATUS_BATTERY_VOLTAGE_H_
#include <Arduino.h>
#include "jade_unoplus/pins_jade_unoplus.h"

/**
 * @brief Read the Vcc voltage from the internal 1.1V reference
 *
 * @return uint16_t
 */
uint16_t readBoardBatteryVoltage();

/**
 * @brief Read the H Bridge battery voltage using the voltage divider
 *
 * @return float
 */
float readAAbatteryVoltage();

#endif  // JADE_UNOPLUS_SYSTEM_STATUS_BATTERY_VOLTAGE_H_
