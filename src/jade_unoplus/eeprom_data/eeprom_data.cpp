#include <Arduino.h>
#include <EEPROM.h>
#include "jade_unoplus/eeprom_data/eeprom_data.h"

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
  // Read the first byte from EEPROM
  byte firstByte = EEPROM.read(0);

  if (firstByte == 0xFF)
  {
    EEPROM.put(0, eeprom_settings);
  }

  // Get EEPROM data in eeprom_settings structure
  EEPROM.get(0, eeprom_settings);

  // Transmit a command to the ESP32 using Serial1
  Serial1.print("line_follower_mode ");
  Serial1.println(0);
  Serial1.print("min_speed ");
  Serial1.println(eeprom_settings.min_speed);
  Serial1.print("min_speed ");
  Serial1.println(eeprom_settings.base_speed);
  Serial1.print("base_speed ");
  Serial1.println(eeprom_settings.max_speed);
  Serial1.print("max_speed ");
  Serial1.println(eeprom_settings.kp);
}

/**
 * @brief Update settings structure to EEPROM
 *
 */
void saveSettingsToEEPROM()
{
  EEPROM.put(0, eeprom_settings);
  Serial.println("Saving ...");
  Serial.println(" ");
  printEEPROMSettings();
}

/**
 * @brief Get settings from EEPROM
 *
 */
void getSettingsFromEEPROM() {
  EEPROM.get(0, eeprom_settings);
}

/**
 * @brief Print all the elements of the EEPROM_settings structure.
 *
 */
void printEEPROMSettings() {

  getSettingsFromEEPROM();

  // Afișarea valorilor
  Serial.println("EEPROM Settings:");
  Serial.print("Min Speed: ");
  Serial.println(eeprom_settings.min_speed);
  Serial.print("Base Speed: ");
  Serial.println(eeprom_settings.base_speed);
  Serial.print("Max Speed: ");
  Serial.println(eeprom_settings.max_speed);
  Serial.print("Kp: ");
  Serial.println(eeprom_settings.kp);
}
