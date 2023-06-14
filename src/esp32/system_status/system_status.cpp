#include "esp32/system_status/system_status.h"

/**
 * @brief System status loop
 *
 */
void refreshSystemStatus() {
  systemStatus.wifi = WiFi.status();
  systemStatus.cloud = ArduinoCloud.connected();
}
