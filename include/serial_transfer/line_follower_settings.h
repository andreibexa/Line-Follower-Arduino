#ifndef INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_
#define INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_

#include <stdint.h>

// Line follower settings
extern bool lineFollowerMode;
extern bool avoidObstacleMode;
extern unsigned int minSpeed;
extern unsigned int baseSpeed;
extern unsigned int maxSpeed;
extern float kp;

#endif  // INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_
