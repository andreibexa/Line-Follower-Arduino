#ifndef JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
#define JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_

#include "serial_transfer/line_follower_settings.h"
#include <Arduino.h>
#include <EEPROM.h>

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM();

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings();

#endif  // JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
