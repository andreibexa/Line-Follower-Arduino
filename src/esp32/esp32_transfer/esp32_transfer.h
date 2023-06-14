#ifndef SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_
#define SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_

#include "transfer/enum_packet_id.h"
#include "esp32/esp32_transfer/transmit.h"
#include "esp32/esp32_transfer/receive.h"
#include <SerialTransfer.h>

extern SerialTransfer ESP32Transfer;

/**
 * @brief Config Serial Transfer
 *
 */
void setupESP32Transfer();

/**
 * @brief Loop Serial Transfer
 *
 */
void loopESP32Transfer();

#endif  // SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_
