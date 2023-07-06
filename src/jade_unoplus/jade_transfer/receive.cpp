#include "jade_unoplus/jade_transfer/receive.h"

STRUCT_ESP32_STATUS esp32Status;

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  // Create a copy of the current settings
  bool avoidObstacleModeTmp = avoidObstacleMode;
  int minSpeedTmp = minSpeed;
  int baseSpeedTmp = baseSpeed;
  int maxSpeedTmp = maxSpeed;
  float kpTmp = kp;

  // Receive the new settings
  uint16_t recSize = 0;
  recSize = serialTransfer.rxObj(lineFollowerMode, recSize);
  recSize = serialTransfer.rxObj(avoidObstacleMode, recSize);
  recSize = serialTransfer.rxObj(baseSpeed, recSize);
  recSize = serialTransfer.rxObj(maxSpeed, recSize);
  recSize = serialTransfer.rxObj(minSpeed, recSize);
  recSize = serialTransfer.rxObj(kp, recSize);

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
