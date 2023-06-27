#include "jade_unoplus/jade_transfer/receive.h"

STRUCT_ESP32_STATUS esp32Status;

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  // Create a copy of the current settings
  bool avoidObstacleMode = lineFollowerSettings.avoidObstacleMode;
  uint8_t minSpeed = lineFollowerSettings.minSpeed;
  uint8_t baseSpeed = lineFollowerSettings.baseSpeed;
  uint8_t maxSpeed = lineFollowerSettings.maxSpeed;
  float kp = lineFollowerSettings.kp;

  // Receive the new settings
  serialTransfer.rxObj(lineFollowerSettings);

  // Save lineFollowerSettings to EEPROM
  if (avoidObstacleMode != lineFollowerSettings.avoidObstacleMode
      || minSpeed != lineFollowerSettings.minSpeed
      || baseSpeed != lineFollowerSettings.baseSpeed
      || maxSpeed != lineFollowerSettings.maxSpeed || kp != lineFollowerSettings.kp) {
    saveLineFollowerSettings();
  }

/*   Serial.println("Receive lineFollowerSettings from ESP32:");
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
  Serial.println(); */
}

/**
 * @brief Receive the ESP32 esp32Status
 *
 */
void receiveESP32Status() {
  // Receive the esp32Status
  uint16_t recSize = 0;
  serialTransfer.rxObj(esp32Status, recSize);
}
