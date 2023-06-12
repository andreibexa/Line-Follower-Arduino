#ifndef SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
#define SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_

#include <HTTPClient.h>
#include <WiFiManager.h>  // https://github.com/tzapu/WiFiManager

// [HTTP] handle route /line-follower
void routeLineFollower();

// [HTTP] bind server callback
void bindServerCallback();

// [WIFI] setup wifi manager
void setupWifiManager();

#endif  // SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
