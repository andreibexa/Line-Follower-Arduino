#include "esp32/esp32_transfer/receive.h"

bool isLineFollowerSettingsReceived = false;

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings() {
  uint16_t recSize = 0;

  if (serialTransfer.available()) {
    recSize = serialTransfer.rxObj(lineFollowerMode, recSize);
    recSize = serialTransfer.rxObj(avoidObstacleMode, recSize);
    recSize = serialTransfer.rxObj(baseSpeed, recSize);
    recSize = serialTransfer.rxObj(maxSpeed, recSize);
    recSize = serialTransfer.rxObj(minSpeed, recSize);
    recSize = serialTransfer.rxObj(kp, recSize);
  }
}
