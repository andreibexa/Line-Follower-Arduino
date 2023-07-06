#include "jade_unoplus/jade_transfer/transmit.h"

/**
 * @brief Transmit the line follower settings to ESP32
 *
 */
void transmitLineFollowerSettings() {
  // Request received
  serialTransfer.rxObj(1);

  uint16_t sendSize = 0;
  sendSize = serialTransfer.txObj(lineFollowerMode, sendSize);
  sendSize = serialTransfer.txObj(avoidObstacleMode, sendSize);
  sendSize = serialTransfer.txObj(baseSpeed, sendSize);
  sendSize = serialTransfer.txObj(maxSpeed, sendSize);
  sendSize = serialTransfer.txObj(minSpeed, sendSize);
  sendSize = serialTransfer.txObj(kp, sendSize);

  // Send buffer
  serialTransfer.sendData(sendSize, PacketId::kLocalLineFollowerSettings);
}
