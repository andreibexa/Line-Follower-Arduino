#ifndef LINE_FOLLOWER_STRUCT_SETTINGS_H_
#define LINE_FOLLOWER_STRUCT_SETTINGS_H_

#include <stdint.h>

struct __attribute__((packed)) STRUCT_LINE_FOLLOWER_SETTINGS {
  bool lineFollowerMode;
  uint8_t minSpeed;
  uint8_t baseSpeed;
  uint8_t maxSpeed;
  float kp;
};

extern STRUCT_LINE_FOLLOWER_SETTINGS lineFollowerSettings;

#endif  // LINE_FOLLOWER_STRUCT_SETTINGS_H_
