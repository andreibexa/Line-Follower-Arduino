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
  // Truncate the 32-bit variables to 8 bits by masking with 0xFF
  uint8_t minSpeed8 = (uint8_t)minSpeed;
  uint8_t baseSpeed8 = (uint8_t)baseSpeed;
  uint8_t maxSpeed8 = (uint8_t)maxSpeed;

  uint16_t sendSize = 0;
  sendSize = serialTransfer.txObj(lineFollowerMode, sendSize);
  sendSize = serialTransfer.txObj(avoidObstacleMode, sendSize);
  sendSize = serialTransfer.txObj(minSpeed8, sendSize);
  sendSize = serialTransfer.txObj(baseSpeed8, sendSize);
  sendSize = serialTransfer.txObj(maxSpeed8, sendSize);
  sendSize = serialTransfer.txObj(kp, sendSize);

  serialTransfer.sendData(sendSize, PacketId::kCloudLineFollowerSettings);

  // Serial print all the above received  settings
  Serial.print("lineFollowerMode ");
  Serial.println(lineFollowerMode);

  Serial.print("avoidObstacleMode ");
  Serial.println(avoidObstacleMode);

  Serial.print("minSpeed ");
  Serial.println(minSpeed);

  Serial.print("baseSpeed ");
  Serial.println(baseSpeed);

  Serial.print("maxSpeed ");
  Serial.println(maxSpeed);

  Serial.print("kp ");
  Serial.println(kp);
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
