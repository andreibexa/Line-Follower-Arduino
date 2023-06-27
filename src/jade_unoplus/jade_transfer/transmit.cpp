#include "jade_unoplus/jade_transfer/transmit.h"

/**
 * @brief Transmit the struct lineFollowerSettings to ESP32
 *
 */
void transmitLineFollowerSettings() {
  // Request received
  serialTransfer.rxObj(1);

  // Use this variable to keep track of how many
  // bytes we're stuffing in the transmit buffer
  uint16_t sendSize = 0;

  // Stuff buffer with struct
  sendSize = serialTransfer.txObj(lineFollowerSettings, sendSize);

  // Send buffer
  serialTransfer.sendData(sendSize, PacketId::kLocalLineFollowerSettings);

/*   Serial.println("Transmit lineFollowerSettings to ESP32:");
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
