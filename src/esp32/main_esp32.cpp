
#include <Arduino.h>

#include "esp32/esp32_transfer/esp32_transfer.h"
#include "esp32/thing_properties/thing_properties.h"
#include "esp32/wifi_manager/wifi_manager.h"

// Put your setup code here, to run once:
void setup() {
  Serial.begin(115200);

  // Setup wifi manager
  setupWifiManager();

  // Setup ESP32 Serial2 Transfer
  setupESP32Transfer();

  if (WiFi.status() == WL_CONNECTED) {
    initThingProperties();

    // Connect to Arduino IoT Cloud
    ArduinoCloud.begin(ArduinoIoTPreferredConnection);

    Serial.println("Connected to Wireless");

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
}

void loop() {
  // put your main code here, to run repeatedly:
  ArduinoCloud.update();

  // Loop Serial Transfer
  loopESP32Transfer();
}
