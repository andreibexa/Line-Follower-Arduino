#include "esp32/esp32_transfer/esp32_transfer.h"

SerialTransfer serialTransfer;

// Array of callbacks.
// The order of the callbacks in the callbackArr array should match the order of
// the enum PacketId in the include/enum_packet_id.h file. This ensures that the
// correct callback function is called when a specific packet with a
// corresponding PacketId is received.
const functionPtr callbackArr[] = { receiveLineFollowerSettings };

/**
 * @brief Config Serial Transfer
 *
 */
void setupSerialTransfer() {
  Serial2.begin(9600, SERIAL_8N1, 16, 17);

  // Config Serial Transfer
  configST transferConfig;
  transferConfig.debug = true;
  transferConfig.callbacks = callbackArr;
  transferConfig.callbacksLen = sizeof(callbackArr) / sizeof(functionPtr);

  // Begin Serial Transfer
  serialTransfer.begin(Serial2, transferConfig);
}

/**
 * @brief Loop Serial Transfer
 *
 */
void loopSerialTransfer() {
  // Check for available serial packets and invoke callbacks
  serialTransfer.tick();
}
