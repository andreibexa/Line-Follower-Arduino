
#include <Arduino.h>

#include "esp32/esp32_transfer/esp32_transfer.h"
#include "esp32/system_status/system_status.h"
#include "esp32/thing_properties/thing_properties.h"
#include "esp32/wifi_manager/wifi_manager.h"

// Put your setup code here, to run once:
void setup() {
  Serial.begin(115200);

  // Setup wifi manager in blocking mode, till the access point is configured.
  setupWifiManager();

  // Setup ESP32 Serial2 Transfer
  setupSerialTransfer();

  initThingProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  /*
      The following function allows you to obtain more information
      related to the state of network and IoT Cloud connection and errors
      the higher number the more granular information you’ll get.
      The default is 0 (only errors).
      Maximum is 4
    */
  // setDebugMessageLevel(2);
  // ArduinoCloud.printDebugInfo();
}

void loop() {
  // put your main code here, to run repeatedly:

  // Loop WiFi Manager
  loopWiFiManager();

  // Loop System Status
  refreshESP32Status();

  // Loop Serial Transfer
  loopSerialTransfer();

  // Update Arduino Cloud if WiFi is connected
  if (WiFi.status() == WL_CONNECTED) {
    ArduinoCloud.update();
  }
}
