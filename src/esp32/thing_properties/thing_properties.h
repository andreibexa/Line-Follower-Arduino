#ifndef SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
#define SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_

#include "esp32/esp32_transfer/esp32_transfer.h"
#include "esp32/secrets.h"
#include <ArduinoIoTCloud.h>

extern WiFiConnectionHandler ArduinoIoTPreferredConnection;

extern bool lineFollowerMode;
extern int baseSpeed;
extern int maxSpeed;
extern int minSpeed;
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
void initThingProperties();

void onIoTSync();

#endif  // SRC_ESP32_THING_PROPERTIES_THING_PROPERTIES_H_
