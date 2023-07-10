#include "jade_unoplus/jade_transfer/receive.h"

STRUCT_ESP32_STATUS esp32Status;

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  // Variables converted to 8-bit values
  uint8_t minSpeed8;
  uint8_t baseSpeed8;
  uint8_t maxSpeed8;

  // Create a temporary copy of the current line follower settings
  bool avoidObstacleModeTmp = avoidObstacleMode;
  unsigned int minSpeedTmp = minSpeed;
  unsigned int baseSpeedTmp = baseSpeed;
  unsigned int maxSpeedTmp = maxSpeed;
  float kpTmp = kp;

  // Receive the new settings
  uint16_t recSize = 0;
  recSize = serialTransfer.rxObj(lineFollowerMode, recSize);
  recSize = serialTransfer.rxObj(avoidObstacleMode, recSize);
  recSize = serialTransfer.rxObj(minSpeed8, recSize);
  recSize = serialTransfer.rxObj(baseSpeed8, recSize);
  recSize = serialTransfer.rxObj(maxSpeed8, recSize);
  recSize = serialTransfer.rxObj(kp, recSize);

  // Assigning received 8-bit values to corresponding int variables
  minSpeed = minSpeed8;
  baseSpeed = baseSpeed8;
  maxSpeed = maxSpeed8;

  // Serial print all the above received  settings
  Serial.print("baseSpeed ");
  Serial.println(baseSpeed);

  Serial.print("maxSpeed ");
  Serial.println(maxSpeed);


  // Save line follower settings to EEPROM
  if (avoidObstacleModeTmp != avoidObstacleMode || minSpeedTmp != minSpeed
      || baseSpeedTmp != baseSpeed || maxSpeedTmp != maxSpeed || kpTmp != kp) {
    saveLineFollowerSettings();

    // Play a sound
    playSequence(S_BUTTON_PUSHED);
  }
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


/**
 * @brief Receive the direction of the remote control
 *
 */
void receiveDirection() {
  // Receive direction command
  uint16_t recSize = 0;
  uint8_t direction = 0;
  serialTransfer.rxObj(direction, recSize);

  // Change the direction and speed
  setDirection(direction, 200);
}
