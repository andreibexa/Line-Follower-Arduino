#include "esp32/esp32_transfer/transmit.h"

/**
 * @brief  Transmit request to retrieve the lineFollowerSettings
 *
 */
void requestLineFollowerSettings() {
  ESP32Transfer.sendData(1, PacketId::kLocalLineFollowerSettings);

  Serial.println("Request lineFollowerSettings from Jade");
  Serial.println();
}

/**
 * @brief Transmit cloud data of the lineFollowerSettings
 *
 */
void transmitLineFollowerSettings() {
  // Inverse the local variables with the received values
  lineFollowerSettings.lineFollowerMode = lineFollowerMode;
  lineFollowerSettings.baseSpeed = baseSpeed;
  lineFollowerSettings.maxSpeed = maxSpeed;
  lineFollowerSettings.minSpeed = minSpeed;
  lineFollowerSettings.kp = kp;

  Serial.println("Transmit lineFollowerSettings to Jade:");
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

  uint16_t sendSize = 0;
  sendSize = ESP32Transfer.txObj(lineFollowerSettings, sendSize);
  ESP32Transfer.sendData(sendSize, PacketId::kCloudLineFollowerSettings);
}
