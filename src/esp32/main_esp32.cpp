
#include <Arduino.h>
// Arduino cloud
#include "thingProperties.h"
#include "wifi_manager/wifi_manager.h"
#include <ArduinoIoTCloud.h>
// Put your setup code here, to run once:
void setup()
{
  Serial.begin(9600);

  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  // Setup wifi manager
  setup_wifi_manager();

  if (WiFi.status() == WL_CONNECTED)
  {
    // Defined in thingProperties.h
    initProperties();

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
    /*
     setDebugMessageLevel(2);
     ArduinoCloud.printDebugInfo();
    */
  }
}

void loop()
{
  // put your main code here, to run repeatedly:

  ArduinoCloud.update();
}
