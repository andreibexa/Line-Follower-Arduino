#include "esp32/esp32_transfer/receive.h"

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  // Variables converted to 8-bit values
  uint8_t minSpeed8;
  uint8_t baseSpeed8;
  uint8_t maxSpeed8;

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

  Serial.print("RECEIVE SETTINGS: ");
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
