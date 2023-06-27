#include "esp32/esp32_transfer/receive.h"

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  serialTransfer.rxObj(lineFollowerSettings);

  // Update the Arduino Cloud variables with the received values
  lineFollowerMode = lineFollowerSettings.lineFollowerMode;
  avoidObstacleMode = lineFollowerSettings.avoidObstacleMode;
  baseSpeed = lineFollowerSettings.baseSpeed;
  maxSpeed = lineFollowerSettings.maxSpeed;
  minSpeed = lineFollowerSettings.minSpeed;
  kp = lineFollowerSettings.kp;

  Serial.println("Receive lineFollowerSettings from Jade:");
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
}