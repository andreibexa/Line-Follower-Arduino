#ifndef ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
#define ESP32_THING_PROPERTIES_THING_PROPERTIES_H_

#include "esp32/thing_properties/secrets.h"
#include "esp32/esp32_transfer/transmit.h"
#include "esp32/esp32_transfer/receive.h"
#include "serial_transfer/enum_direction.h"
#include "serial_transfer/line_follower_settings.h"
#include <ArduinoIoTCloud.h>

extern WiFiConnectionHandler ArduinoIoTPreferredConnection;

// Remote control
extern bool moveBackward;
extern bool moveForward;
extern bool moveLeft;
extern bool moveRight;

/*
  Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLineFollowerModeChange();

/*
  Since avoidObstacleMode is READ_WRITE variable, onavoidObstacleModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onAvoidObstacleModeChange();

/*
  Since MaxSpeed is READ_WRITE variable, onMaxSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMaxSpeedChange();

/*
  Since BaseSpeed is READ_WRITE variable, onBaseSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onBaseSpeedChange();

/*
  Since MinSpeed is READ_WRITE variable, onMinSpeedChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onMinSpeedChange();

/*
  Since Kp is READ_WRITE variable, onKpChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onKpChange();

/**
 * @brief Initialize the properties for Arduino Cloud
 *
 */
void initThingProperties();

/**
 * @brief Copy the SSID and PASS from the preferred connection
 *
 */
void preferredConnectionHandler(char* ssid, char* pass);

#endif  // ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
