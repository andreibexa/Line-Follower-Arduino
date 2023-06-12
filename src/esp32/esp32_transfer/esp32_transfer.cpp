#include "esp32/esp32_transfer/esp32_transfer.h"

SerialTransfer ESP32Transfer;

// Array of callbacks.
// The order of the callbacks in the callbackArr array should match the order of
// the enum PacketId in the include/enum_packet_id.h file. This ensures that the
// correct callback function is called when a specific packet with a
// corresponding PacketId is received.
const functionPtr callbackArr[] = { receiveLineFollowerSettings };

STRUCT_LINE_FOLLOWER_SETTINGS lineFollowerSettings;

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  ESP32Transfer.rxObj(lineFollowerSettings);

  // Update the Arduino Cloud variables with the received values
  lineFollowerMode = lineFollowerSettings.lineFollowerMode;
  baseSpeed = lineFollowerSettings.baseSpeed;
  maxSpeed = lineFollowerSettings.maxSpeed;
  minSpeed = lineFollowerSettings.minSpeed;
  kp = lineFollowerSettings.kp;

  Serial.println("Receive lineFollowerSettings from Jade:");
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
}

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

/**
 * @brief Config Serial Transfer
 *
 */
void setupESP32Transfer() {
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  // Config Serial Transfer
  configST transferConfig;
  transferConfig.debug = true;
  transferConfig.callbacks = callbackArr;
  transferConfig.callbacksLen = sizeof(callbackArr) / sizeof(functionPtr);

  // Begin Serial Transfer
  ESP32Transfer.begin(Serial2, transferConfig);

  // Request the lineFollowerSettings from Jade UnoPlus board
  requestLineFollowerSettings();
}

/**
 * @brief Loop Serial Transfer
 *
 */
void loopESP32Transfer() {
  // Check for available serial packets and invoke callbacks
  ESP32Transfer.tick();
}
