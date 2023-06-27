#ifndef ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H_
#define ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H_
#include "esp32/esp32_transfer/transmit.h"
#include <WiFiManager.h>
#include <ArduinoIoTCloud.h>

/**
 * @brief Refresh and transmit system status every 1 second
 *
 */
void refreshESP32Status();

#endif  // ESP32_SYSTEM_STATUS_SYSTEM_STATUS_H_
