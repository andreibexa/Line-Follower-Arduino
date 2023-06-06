#include "esp32/wifi_manager/wifi_manager.h"

// WiFiManager, Local intialization. Once its business is done, there is no need to keep it around
WiFiManager wm;

// [WIFI] setup wifi manager
void setup_wifi_manager()
{
  WiFi.mode(WIFI_STA); // explicitly set mode, esp defaults to STA+AP
  // it is a good practice to make sure your code sets wifi mode how you want it.

  // reset settings - wipe stored credentials for testing
  // these are stored by the esp library
  // wm.resetSettings();

  // Disable debug
  wm.setDebugOutput(false);
  delay(1000);

  // Set Hostname
  wm.setHostname(hostname);

  // Automatically connect using saved credentials,
  // if connection fails, it starts an access point with the specified name ( "AutoConnectAP"),
  // if empty will auto generate SSID, if password is blank it will be anonymous AP (wm.autoConnect())
  // then goes into a blocking loop awaiting configuration and will return success result
  bool res;
  res = wm.autoConnect(hostname, password); // password protected ap

  if (!res)
  {
    Serial.println("Failed to connect");
    // ESP.restart();
  }
  else
  {
    // if you get here you have connected to the WiFi
    Serial.println("connected...yeey :)");
  }
}
