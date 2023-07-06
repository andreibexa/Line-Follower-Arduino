#ifndef INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_
#define INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_

#include <stdint.h>

// Line follower settings
extern bool lineFollowerMode;
extern bool avoidObstacleMode;
extern int minSpeed;
extern int baseSpeed;
extern int maxSpeed;
extern float kp;

#endif  // INCLUDE_SERIAL_TRANSFER_LINE_FOLLOWER_SETTINGS_H_
