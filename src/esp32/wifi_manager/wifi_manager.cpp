#include "esp32/wifi_manager/wifi_manager.h"

// WiFiManager, Local intialization. Once its business is done, there is no need
// to keep it around
WiFiManager wm;

char const hostname[] = "LINE-FOLLOWER-7598";
char const password[] = "password";
// char ssid[32];  // SSID char limit
// char pass[63];  // PASS char limit

// Setup wifi manager
void setupWifiManager() {
  WiFi.mode(WIFI_STA);  // explicitly set mode, esp defaults to STA+AP
  // it is a good practice to make sure your code sets wifi mode how you want
  // it.

  // reset settings - wipe stored credentials for testing
  // these are stored by the esp library
  // wm.resetSettings();

  // Debug
  wm.setDebugOutput(false);

  // Set Hostname
  wm.setHostname(hostname);

  // Continue, even if not connected to WiFi
  wm.setConfigPortalBlocking(false);

  // Set a timeout period for the configuration portal
  wm.setConfigPortalTimeout(180);

  // Arduino Cloud handles the WiFi connection to the router.
  /*
    String str_ssid = wm.getWiFiSSID(false);
    String str_pass = wm.getWiFiPass(false);
    preferredConnectionHandler(ssid, pass);
 */

  // Automatically connect using saved credentials,
  // if connection fails, it starts an access point with the specified name (
  // "AutoConnectAP"), if empty will auto generate SSID, if password is blank
  // it will be anonymous AP (wm.autoConnect()) then goes into a blocking loop
  // awaiting configuration and will return success result
  bool res;
  res = wm.autoConnect(hostname, password);  // password protected ap

  if (!res) {
    Serial.println("Failed to connect to wireless");
    // ESP.restart();
  } else {
    // if you get here you have connected to the WiFi
    Serial.println("Connected to wireless");
  }
}

/**
 * @brief Loop Wifi Manager
 *
 */
void loopWiFiManager() {
  // Non blocking function for the WiFi manager
  wm.process();
}