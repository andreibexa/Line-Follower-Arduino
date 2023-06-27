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
  EEPROM.get(0, lineFollowerSettings.baseSpeed);
  EEPROM.get(1, lineFollowerSettings.minSpeed);
  EEPROM.get(2, lineFollowerSettings.maxSpeed);
  EEPROM.get(3, lineFollowerSettings.kp);
  EEPROM.get(4, lineFollowerSettings.avoidObstacleMode);
}

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings() {
  EEPROM.put(0, lineFollowerSettings.baseSpeed);
  EEPROM.put(1, lineFollowerSettings.minSpeed);
  EEPROM.put(2, lineFollowerSettings.maxSpeed);
  EEPROM.put(3, lineFollowerSettings.kp);
  EEPROM.put(4, lineFollowerSettings.avoidObstacleMode);

  Serial.println("Saving to EEPROM");
  /*
  Serial.print("lineFollowerMode ");
  Serial.println(lineFollowerSettings.lineFollowerMode);
  Serial.print("avoidObstacleMode ");
  Serial.println(lineFollowerSettings.avoidObstacleMode);
  Serial.print("minSpeed ");
  Serial.println(lineFollowerSettings.minSpeed);
  Serial.print("baseSpeed ");
  Serial.println(lineFollowerSettings.baseSpeed);
  Serial.print("maxSpeed ");
  Serial.println(lineFollowerSettings.maxSpeed);
  Serial.print("kp ");
  Serial.println(lineFollowerSettings.kp);
  */
}
