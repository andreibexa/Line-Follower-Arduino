#ifndef INCLUDE_TRANSFER_STRUCT_SYSTEM_STATUS_H_
#define INCLUDE_TRANSFER_STRUCT_SYSTEM_STATUS_H_

#include <stdint.h>

struct __attribute__((packed)) STRUCT_SYSTEM_STATUS {
  uint8_t wifiStatus;
  uint8_t cloudStatus;
};

extern STRUCT_SYSTEM_STATUS systemStatus;

#endif  // INCLUDE_TRANSFER_STRUCT_SYSTEM_STATUS_H_
