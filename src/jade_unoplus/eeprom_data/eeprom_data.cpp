#include <Arduino.h>
#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/eeprom_data/commander.h"

// Structure for EEPROM data
EEPROM_settings eeprom_settings = {
    .min_speed = 0,
    .base_speed = 180,
    .max_speed = 255,
    .kp = 0.38,
};

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM()
{
  EEPROM.begin();

  // Read the first byte from EEPROM
  uint8_t firstByte = EEPROM.read(0);

  if (firstByte == 0xFF)
  {
    EEPROM.put(0, eeprom_settings);
  }

  // Get EEPROM data in eeprom_settings structure
  EEPROM.get(0, eeprom_settings);
}

/**
 * @brief Save settings structure to EEPROM
 *
 */
void saveSettingsToEEPROM()
{
  EEPROM.put(0, eeprom_settings);
}

/**
 * @brief Print all the elements of the EEPROM_settings structure.
 * Thank you ChatGPT 😎
 *
 */
void printEEPROMSettings()
{
  uint8_t *ptr = reinterpret_cast<uint8_t *>(&eeprom_settings);
  size_t size = sizeof(eeprom_settings);

  for (size_t i = 0; i < size; ++i)
  {
    Serial.print("EEPROM ");
    Serial.print(i);
    Serial.print(": ");
    Serial.println(ptr[i]);
  }
}
