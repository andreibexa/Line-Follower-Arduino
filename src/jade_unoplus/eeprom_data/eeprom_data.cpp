#include "jade_unoplus/eeprom_data/eeprom_data.h"

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM() {
  // Read the first byte from EEPROM
  byte firstByte = EEPROM.read(0);

  if (firstByte == 0xFF) {
    saveLineFollowerSettings();
  }

  // Get EEPROM data
  EEPROM.get(0, baseSpeed);
  EEPROM.get(1, minSpeed);
  EEPROM.get(2, maxSpeed);
  EEPROM.get(3, kp);
  EEPROM.get(4, avoidObstacleMode);
}

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings() {
  EEPROM.put(0, baseSpeed);
  EEPROM.put(1, minSpeed);
  EEPROM.put(2, maxSpeed);
  EEPROM.put(3, kp);
  EEPROM.put(4, avoidObstacleMode);

  Serial.println("Save line follower settings to EEPROM");
}
