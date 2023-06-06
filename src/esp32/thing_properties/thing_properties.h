#ifndef SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
#define SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_

#include <HardwareSerial.h>
#include <ArduinoIoTCloud.h>
#include "esp32/secrets.h"

extern WiFiConnectionHandler ArduinoIoTPreferredConnection;

extern bool line_follower_mode;
extern int base_speed;
extern int max_speed;
extern int min_speed;
extern float kp;

/*
  Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLineFollowerModeChange();

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
void initProperties();

#endif // SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
