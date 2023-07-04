#include "esp32/esp32_transfer/transmit.h"

/**
 * @brief  Transmit request to retrieve the lineFollowerSettings
 *
 */
void requestLineFollowerSettings() {
  serialTransfer.sendData(1, PacketId::kLocalLineFollowerSettings);
}

/**
 * @brief Transmit cloud data of the lineFollowerSettings
 *
 */
void transmitLineFollowerSettings() {
  // Inverse the local variables with the received values
  lineFollowerSettings.lineFollowerMode = lineFollowerMode;
  lineFollowerSettings.avoidObstacleMode = avoidObstacleMode;
  lineFollowerSettings.baseSpeed = baseSpeed;
  lineFollowerSettings.maxSpeed = maxSpeed;
  lineFollowerSettings.minSpeed = minSpeed;
  lineFollowerSettings.kp = kp;

  uint16_t sendSize = 0;
  sendSize = serialTransfer.txObj(lineFollowerSettings, sendSize);
  serialTransfer.sendData(sendSize, PacketId::kCloudLineFollowerSettings);
}

/**
 * @brief Transmit the esp32Status to Jade, WiFi and Cloud status
 *
 */
void transmitESP32Status() {
  uint16_t sendSize = 0;
  sendSize = serialTransfer.txObj(esp32Status, sendSize);
  serialTransfer.sendData(sendSize, PacketId::kESP32Status);
}


/**
 * @brief Transmit the direction of the remote control
 *
 * @param direction
 *
 */
void transmitDirection(uint8_t direction) {
  uint16_t sendSize = 0;
  sendSize = serialTransfer.txObj(direction, sendSize);
  serialTransfer.sendData(sendSize, PacketId::kRemoteControlDirection);
}