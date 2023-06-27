#include "esp32/esp32_transfer/transmit.h"

/**
 * @brief  Transmit request to retrieve the lineFollowerSettings
 *
 */
void requestLineFollowerSettings() {
  serialTransfer.sendData(1, PacketId::kLocalLineFollowerSettings);
  Serial.println("Request lineFollowerSettings from Jade");
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

  Serial.println("Transmit lineFollowerSettings to Jade:");
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
  Serial.println();

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
