#include "jade_unoplus/system_status/system_status.h"
#include "jade_unoplus/tone/tone.h"

/**
 * @brief Setup system status
 *
 */
void setupSystemStatus() {
  displayWiFiDisconnected();
  // Blink the multicolor led with blue color
  setMultiColorLed(0, 0, 8, true);
}

/**
 * @brief System status loop called in the main loop
 *
 */
void loopSystemStatus() {
  handleStatusFromESP32();
  displayBatteryStatus();
}

/**
 * @brief Handle the system status based on the esp32Status
 *
 */
void handleStatusFromESP32() {
  // Create temporary variables to store the status
  static uint8_t wifiStatus = 0;
  static uint8_t cloudStatus = 0;

  // Update led or display only if the status has changed
  if (esp32Status.wifi != wifiStatus || esp32Status.cloud != cloudStatus) {

    if (esp32Status.wifi != 3) {  // WiFi connecting ...
      displayWiFiDisconnected();
      // Blink the multicolor led with blue color
      setMultiColorLed(0, 0, 8, true);
    } else if (esp32Status.cloud == 0) {  // Cloud connecting ...
      displayWiFiConnected(esp32Status.wifiSignalStrength);
      charCloudDisconnected();
      // Blink the multicolor led with pink color
      setMultiColorLed(1, 0, 8, true);
    } else if (esp32Status.cloud == 1) {  // Cloud connected
      displayWiFiConnected(esp32Status.wifiSignalStrength);
      charCloudConnected();
      playSequence(S_CONNECTION);
      // Turn on the multicolor led with purple
      setMultiColorLed(1, 0, 8, false);
    }

    // Update the temporary variables
    wifiStatus = esp32Status.wifi;
    cloudStatus = esp32Status.cloud;
  }
}


/**
 * @brief Display the battery status on the LCD
 *
 */
void displayBatteryStatus() {
  // Read the battery voltage each second
  static unsigned long previousMillis = 1000;
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= 1000) {
    previousMillis = currentMillis;

    // Read the 18650 battery voltage
    uint16_t boardBatteryVoltage = readBoardBatteryVoltage();

    // Display the 18650 battery voltage on the LCD
    display18650BatteryVoltage(boardBatteryVoltage);

    // Read the AA battery voltage
    float aaBatteryVoltage = readAAbatteryVoltage();

    // Display the AA battery voltage on the LCD
    displayAAbatteryVoltage(aaBatteryVoltage);
  }
}
