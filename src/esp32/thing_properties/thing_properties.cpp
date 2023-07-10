#include "esp32/thing_properties/thing_properties.h"

// The bellow code is adapted from Arduino IoT Cloud - https://cloud.arduino.com

char SSID[32];  // Network SSID (name)
char PASS[63];  // Network password (use for WPA, or use as key for WEP)

// Line follower settings
bool lineFollowerMode;
bool avoidObstacleMode;
unsigned int minSpeed;
unsigned int baseSpeed;
unsigned int maxSpeed;
float kp;

// Remote control
bool moveBackward;
bool moveForward;
bool moveLeft;
bool moveRight;

/*
  Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLineFollowerModeChange() {
  // Add your code here to act upon LineFollowerMode change
  transmitLineFollowerSettings();
  Serial.print("onLineFollowerModeChange lineFollowerMode ");
  Serial.println(lineFollowerMode);
}

/*
  Since avoidObstacleMode is READ_WRITE variable, onavoidObstacleModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAvoidObstacleModeChange() {
  // Add your code here to act upon avoidObstacleMode change
  transmitLineFollowerSettings();
  Serial.print("onAvoidObstacleModeChange avoidObstacleMode ");
  Serial.println(avoidObstacleMode);
}

/*
  Since MinSpeed is READ_WRITE variable, onMinSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMinSpeedChange() {
  // Add your code here to act upon MinSpeed change
  transmitLineFollowerSettings();
  Serial.print("onMinSpeedChange minSpeed ");
  Serial.println(minSpeed);
}

/*
  Since BaseSpeed is READ_WRITE variable, onBaseSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBaseSpeedChange() {
  // Add your code here to act upon BaseSpeed change
  transmitLineFollowerSettings();
  Serial.print("onBaseSpeedChange baseSpeed ");
  Serial.println(baseSpeed);
}

/*
  Since MaxSpeed is READ_WRITE variable, onMaxSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMaxSpeedChange() {
  // Add your code here to act upon MaxSpeed change
  transmitLineFollowerSettings();
  Serial.print("onMaxSpeedChange maxSpeed ");
  Serial.println(maxSpeed);
}

/*
  Since Kp is READ_WRITE variable, onKpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onKpChange() {
  // Add your code here to act upon Kp change
  transmitLineFollowerSettings();
  Serial.println("onKpChange kp ");
  Serial.println(kp);
}


void onMoveBackwardChange() {
  // Add your code here to act upon MoveBackward change
  if (moveBackward) {
    transmitDirection(BACKWARD);
    return;
  }

  transmitDirection(STOP_SLOW);
}

/*
  Since MoveForward is READ_WRITE variable, onMoveForwardChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoveForwardChange() {
  // Add your code here to act upon MoveForward change
  if (moveForward) {
    transmitDirection(FORWARD);
    return;
  }

  transmitDirection(STOP_SLOW);
}

/*
  Since MoveLeft is READ_WRITE variable, onMoveLeftChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoveLeftChange() {
  // Add your code here to act upon MoveLeft change
  if (moveLeft) {
    transmitDirection(LEFT_WIDE_FORWARD);
    return;
  }

  transmitDirection(STOP_SLOW);
}

/*
  Since MoveRight is READ_WRITE variable, onMoveRightChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMoveRightChange() {
  // Add your code here to act upon MoveRight change
  if (moveRight) {
    transmitDirection(RIGHT_WIDE_FORWARD);
    return;
  }

  transmitDirection(STOP_SLOW);
}

/*
   On first Arduino Cloud Sync - synchronize local variables with cloud
  variables
 */
void onIoTSync() {
  // Line follower settings
  ArduinoCloud.addProperty(lineFollowerMode, READWRITE, ON_CHANGE, onLineFollowerModeChange);
  ArduinoCloud.addProperty(avoidObstacleMode, READWRITE, ON_CHANGE, onAvoidObstacleModeChange);
  ArduinoCloud.addProperty(minSpeed, READWRITE, ON_CHANGE, onMinSpeedChange);
  ArduinoCloud.addProperty(baseSpeed, READWRITE, ON_CHANGE, onBaseSpeedChange);
  ArduinoCloud.addProperty(maxSpeed, READWRITE, ON_CHANGE, onMaxSpeedChange);
  ArduinoCloud.addProperty(kp, READWRITE, ON_CHANGE, onKpChange);
}

/*
  Initialize Arduino Cloud
*/
void initThingProperties() {
  // Request the lineFollowerSettings from Jade UnoPlus board
  requestLineFollowerSettings();

  // Auth data
  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);

  // Synchronize local variables with cloud variables
  ArduinoCloud.addCallback(ArduinoIoTCloudEvent::SYNC, onIoTSync);

  // Remote control commands
  ArduinoCloud.addProperty(moveBackward, READWRITE, ON_CHANGE, onMoveBackwardChange);
  ArduinoCloud.addProperty(moveForward, READWRITE, ON_CHANGE, onMoveForwardChange);
  ArduinoCloud.addProperty(moveLeft, READWRITE, ON_CHANGE, onMoveLeftChange);
  ArduinoCloud.addProperty(moveRight, READWRITE, ON_CHANGE, onMoveRightChange);
}

/*
  Copy the SSID and PASS from the WiFi manager library
*/
void preferredConnectionHandler(char* ssid, char* pass) {
  strcpy(SSID, ssid);
  strcpy(PASS, pass);
}

// Wifi manager extension handles the preferred connection method for Arduino
// IoT. This line does not affect the wifi connection.
WiFiConnectionHandler ArduinoIoTPreferredConnection("none", "none");
