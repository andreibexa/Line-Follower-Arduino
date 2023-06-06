#ifndef SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
#define SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_

#include <Arduino.h>

struct EEPROM_settings
{
  uint8_t min_speed;
  uint8_t base_speed;
  uint8_t max_speed;
  float kp;
};

extern EEPROM_settings eeprom_settings;

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM();

/**
 * @brief Read EEPROM settings
 */
void readEEPROMSettings();

/**
 * @brief Writes the settings data to the EEPROM.
 *
 */
void saveSettingsToEEPROM();

/**
 * @brief Print all the elements of the EEPROM_settings structure.
 *
 */
void printEEPROMSettings();

#endif // SRC_JADE_UNOPLUS_EEPROM_DATA_EEPROM_DATA_H_
