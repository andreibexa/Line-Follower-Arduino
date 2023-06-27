#include "esp32/system_status/system_status.h"

STRUCT_ESP32_STATUS esp32Status;

/**
 * @brief Refresh and transmit system status every 1 second
 *
 */
void refreshESP32Status() {
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;
  const unsigned long interval = 1000;

  if (currentMillis - previousMillis >= interval) {
    // WiFi status
    esp32Status.wifi = WiFi.status();

    // WiFi signal strength
    esp32Status.wifiSignalStrength = WiFi.RSSI();

    // ArduinoCloud status
    esp32Status.cloud = ArduinoCloud.connected();

    // Transmit ESP32 status
    transmitESP32Status();

    previousMillis = currentMillis;
  }
}
