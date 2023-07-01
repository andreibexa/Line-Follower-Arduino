#ifndef INCLUDE_SERIAL_TRANSFER_STRUCT_ESP32_STATUS_H_
#define INCLUDE_SERIAL_TRANSFER_STRUCT_ESP32_STATUS_H_

#include <stdint.h>

struct __attribute__((packed)) STRUCT_ESP32_STATUS {
  uint8_t wifi;
  uint16_t wifiSignalStrength;
  uint8_t cloud;
};

extern STRUCT_ESP32_STATUS esp32Status;

#endif  // INCLUDE_SERIAL_TRANSFER_STRUCT_ESP32_STATUS_H_
