#ifndef ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
#define ESP32_WIFI_MANAGER_WIFI_MANAGER_H_

#include <HTTPClient.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager
// #include "esp32/thing_properties/thing_properties.h"

// [HTTP] handle route /line-follower
void routeLineFollower();

// [HTTP] bind server callback
void bindServerCallback();

// [WIFI] setup wifi manager
void setupWifiManager();

/**
 * @brief Loop Wifi Manager
 *
 */
void loopWiFiManager();

#endif  // ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
