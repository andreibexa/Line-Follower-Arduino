#ifndef SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
#define SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_

#include "line_follower_struct_settings.h"
#include <Arduino.h>
#include <EEPROM.h>
#include <SoftwareSerial.h>

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM();

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings();

/**
 * @brief Get lineFollowerSettings from EEPROM
 *
 */
void getLineFollowerSettings();

/**
 * @brief Print all the elements of the lineFollowerSettings structure.
 *
 */
void printEEPROMSettings();

#endif  // SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
