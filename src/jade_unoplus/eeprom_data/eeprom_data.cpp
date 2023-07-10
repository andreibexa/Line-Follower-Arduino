#include "jade_unoplus/eeprom_data/eeprom_data.h"

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM() {
  // Read the first byte from EEPROM
  byte firstByte = EEPROM.read(0);

  if (firstByte == 0xFF) {
    // Initialize the line follower settings with default settings
    initializeLineFollowerSettings();

    // Save the line follower settings to EEPROM
    saveLineFollowerSettings();
  }

  // Get EEPROM data
  getEEPROMData();
}

/**
 * @brief Get EEPROM data
 *
 */
void getEEPROMData() {
  EEPROM.get(0, avoidObstacleMode);
  EEPROM.get(1, minSpeed);
  EEPROM.get(2, baseSpeed);
  EEPROM.get(3, maxSpeed);
  EEPROM.get(4, kp);
}

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings() {
  EEPROM.put(0, avoidObstacleMode);
  EEPROM.put(1, minSpeed);
  EEPROM.put(2, baseSpeed);
  EEPROM.put(3, maxSpeed);
  EEPROM.put(4, kp);

  Serial.println("Save the line follower settings to EEPROM");
}
