#ifndef SRC_ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H
#define SRC_ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H
#include "transfer/struct_system_status.h"
#include <WiFiManager.h>
#include <ArduinoIoTCloud.h>

/**
 * @brief Refresh system status structure
 *
 */
void refreshSystemStatus();

#endif  // SRC_ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H
