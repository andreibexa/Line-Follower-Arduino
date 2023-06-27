#ifndef INCLUDE_TRANSFER_STRUCT_LINE_FOLLOWER_SETTINGS_H_
#define INCLUDE_TRANSFER_STRUCT_LINE_FOLLOWER_SETTINGS_H_

#include <stdint.h>

struct __attribute__((packed)) STRUCT_LINE_FOLLOWER_SETTINGS {
  bool lineFollowerMode;
  bool avoidObstacleMode;
  uint8_t minSpeed;
  uint8_t baseSpeed;
  uint8_t maxSpeed;
  float kp;
};

extern STRUCT_LINE_FOLLOWER_SETTINGS lineFollowerSettings;

#endif  // INCLUDE_TRANSFER_STRUCT_LINE_FOLLOWER_SETTINGS_H_
