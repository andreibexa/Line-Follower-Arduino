#ifndef SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
#define SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_

#include <WiFiManager.h> // https://github.com/tzapu/WiFiManager
#include <HTTPClient.h>

char const hostname[] = "LINE-FOLLOWER-7598";
char const password[] = "password";

// [HTTP] handle route /line-follower
void routeLineFollower();

// [HTTP] bind server callback
void bindServerCallback();

// [WIFI] setup wifi manager
void setup_wifi_manager();

#endif // SRC_ESP32_WIFI_MANAGER_WIFI_MANAGER_H_
