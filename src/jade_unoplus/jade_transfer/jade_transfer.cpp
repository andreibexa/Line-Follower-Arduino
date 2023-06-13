#include "jade_unoplus/jade_transfer/jade_transfer.h"

SerialTransfer JadeTransfer;
SoftwareSerial Serial2(RX_PIN, TX_PIN);

// Array of callbacks.
// The order of the callbacks in the callbackArr array should match the order of
// the enum PacketId in the include/enum_packet_id.h file. This ensures that the
// correct callback function is called when a specific packet with a
// corresponding PacketId is received.
const functionPtr callbackArr[] = { transmitLineFollowerSettings, receiveLineFollowerSettings };

/**
 * @brief Transmit the struct lineFollowerSettings
 *
 */
void transmitLineFollowerSettings() {
  // Request received
  JadeTransfer.rxObj(1);
  Serial.println("Transmit lineFollowerSettings to ESP32:");

  // Use this variable to keep track of how many
  // bytes we're stuffing in the transmit buffer
  uint16_t sendSize = 0;

  // Stuff buffer with struct
  sendSize = JadeTransfer.txObj(lineFollowerSettings, sendSize);

  // Send buffer
  JadeTransfer.sendData(sendSize, PacketId::kLocalLineFollowerSettings);

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
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  // Create a copy of the current settings
  uint8_t minSpeed = lineFollowerSettings.minSpeed;
  uint8_t baseSpeed = lineFollowerSettings.baseSpeed;
  uint8_t maxSpeed = lineFollowerSettings.maxSpeed;
  float kp = lineFollowerSettings.kp;

  // Receive the new settings
  JadeTransfer.rxObj(lineFollowerSettings);

  // Save lineFollowerSettings to EEPROM
  if (minSpeed != lineFollowerSettings.minSpeed
      || baseSpeed != lineFollowerSettings.baseSpeed
      || maxSpeed != lineFollowerSettings.maxSpeed || kp != lineFollowerSettings.kp) {
    saveLineFollowerSettings();
  }

  // Stop the Line Follower
  if (lineFollowerSettings.lineFollowerMode == 0) {
    stopLineFollower();
  }



  Serial.println("Receive lineFollowerSettings from ESP32:");
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
 * @brief Config Serial Transfer
 *
 */
void setupSerialTransfer() {
  Serial2.begin(9600);

  // Config Serial Transfer
  configST transferConfig;
  transferConfig.debug = true;
  transferConfig.callbacks = callbackArr;
  transferConfig.callbacksLen = sizeof(callbackArr) / sizeof(functionPtr);

  JadeTransfer.begin(Serial2, transferConfig);
}

/**
 * @brief Loop Serial Transfer
 *
 */
void loopSerialTransfer() {
  // Check for available serial packets and invoke callbacks
  JadeTransfer.tick();
}
