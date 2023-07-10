#include "jade_unoplus/jade_transfer/transmit.h"

/**
 * @brief Transmit the line follower settings to ESP32
 *
 */
void transmitLineFollowerSettings() {
  // Request received
  serialTransfer.rxObj(1);

  // Truncate the 32-bit variables to 8 bits by masking with 0xFF
  uint8_t minSpeed8 = (uint8_t)minSpeed;
  uint8_t baseSpeed8 = (uint8_t)baseSpeed;
  uint8_t maxSpeed8 = (uint8_t)maxSpeed;

  // track of how many bytes we're stuffing in the transmit buffer
  uint16_t sendSize = 0;

  // Stuff buffer with data
  sendSize = serialTransfer.txObj(lineFollowerMode, sendSize);
  sendSize = serialTransfer.txObj(avoidObstacleMode, sendSize);
  sendSize = serialTransfer.txObj(minSpeed8, sendSize);
  sendSize = serialTransfer.txObj(baseSpeed8, sendSize);
  sendSize = serialTransfer.txObj(maxSpeed8, sendSize);
  sendSize = serialTransfer.txObj(kp, sendSize);

  // Send buffer with packet ID
  serialTransfer.sendData(sendSize, PacketId::kLocalLineFollowerSettings);
}
