
#include <Arduino.h>

#include <ArduinoIoTCloud.h>
#include "esp32/thingProperties.h"
#include "esp32/wifi_manager/wifi_manager.h"

// Put your setup code here, to run once:
void setup()
{
  Serial.begin(9600);
  Serial1.begin(9600, SERIAL_8N1, T0, T1);

  // Wait for the serial port to open (if using USB)
  while (!Serial){;}

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
