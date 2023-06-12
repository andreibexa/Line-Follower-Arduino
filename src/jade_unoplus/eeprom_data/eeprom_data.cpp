#include "jade_unoplus/eeprom_data/eeprom_data.h"

/**
 * @brief Initialize EEPROM
 */
void initializeEEPROM() {
  // Read the first byte from EEPROM
  byte firstByte = EEPROM.read(0);

  if (firstByte == 0xFF) { EEPROM.put(0, lineFollowerSettings); }

  // Get EEPROM data in eeprom_settings structure
  EEPROM.get(0, lineFollowerSettings);
}

/**
 * @brief Save lineFollowerSettings to EEPROM
 *
 */
void saveLineFollowerSettings() {
  EEPROM.put(0, lineFollowerSettings);
  Serial.println("Saving lineFollowerSettings to EEPROM");

  printEEPROMSettings();
}

/**
 * @brief Get lineFollowerSettings from EEPROM
 *
 */
void getLineFollowerSettings() {
  EEPROM.get(0, lineFollowerSettings);
}

/**
 * @brief Print all the elements of the lineFollowerSettings structure.
 *
 */
void printEEPROMSettings() {
  getLineFollowerSettings();

  // Print the lineFollowerSettings structure
  Serial.println("lineFollowerSettings from EEPROM:");
  Serial.print("lineFollowerMode ");
  Serial.println(lineFollowerSettings.lineFollowerMode);
  Serial.print("minSpeed ");
  Serial.println(lineFollowerSettings.minSpeed);
  Serial.print("baseSpeed ");
  Serial.println(lineFollowerSettings.baseSpeed);
  Serial.print("maxSpeed ");
  Serial.println(lineFollowerSettings.maxSpeed);
  Serial.print("kp ");
  Serial.println(lineFollowerSettings.kp);
  Serial.println();
}
