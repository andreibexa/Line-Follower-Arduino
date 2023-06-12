#include <esp32/thing_properties/thing_properties.h>

// The bellow code is adapted from Arduino IoT Cloud - https://cloud.arduino.com

float kp;
int baseSpeed;
int maxSpeed;
int minSpeed;
bool lineFollowerMode;

/*
  Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLineFollowerModeChange() {
  // Add your code here to act upon LineFollowerMode change
  transmitLineFollowerSettings();
}

/*
  Since MaxSpeed is READ_WRITE variable, onMaxSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMaxSpeedChange() {
  // Add your code here to act upon MaxSpeed change
  transmitLineFollowerSettings();
}

/*
  Since BaseSpeed is READ_WRITE variable, onBaseSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBaseSpeedChange() {
  // Add your code here to act upon BaseSpeed change
  transmitLineFollowerSettings();
}

/*
  Since MinSpeed is READ_WRITE variable, onMinSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMinSpeedChange() {
  // Add your code here to act upon MinSpeed change
  transmitLineFollowerSettings();
}

/*
  Since Kp is READ_WRITE variable, onKpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onKpChange() {
  // Add your code here to act upon Kp change
  transmitLineFollowerSettings();
}

/**
 * @brief On first Arduino Cloud Sync - synchronize local variables with cloud
 * variables
 *
 */
void onIoTSync() {
  // Request the lineFollowerSettings from Jade UnoPlus board
  requestLineFollowerSettings();

  // Line Follower Mode should be always OFF when the board is powered on
  ArduinoCloud.addProperty(kp, READWRITE, ON_CHANGE, onKpChange);
  ArduinoCloud.addProperty(baseSpeed, READWRITE, ON_CHANGE, onKpChange);
  ArduinoCloud.addProperty(minSpeed, READWRITE, ON_CHANGE, onMinSpeedChange);
  ArduinoCloud.addProperty(maxSpeed, READWRITE, ON_CHANGE, onMaxSpeedChange);
  ArduinoCloud.addProperty(lineFollowerMode, READWRITE, ON_CHANGE, onLineFollowerModeChange);
}

/**
 * @brief Initialize the properties for Arduino Cloud
 *
 */
void initThingProperties() {
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  // On first Arduino Cloud Sync - synchronize local variables with cloud
  // variables
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, onIoTSync);
}

// Wifi manager extension handles the preferred connection method for Arduino
// IoT. This line does not affect the wifi connection.
WiFiConnectionHandler ArduinoIoTPreferredConnection("none", "none");
