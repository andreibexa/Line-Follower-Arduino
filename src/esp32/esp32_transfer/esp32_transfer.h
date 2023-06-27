#ifndef SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_
#define SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_

#include "esp32/esp32_transfer/transmit.h"
#include "esp32/esp32_transfer/receive.h"


/**
 * @brief Config Serial Transfer
 *
 */
void setupSerialTransfer();

/**
 * @brief Loop Serial Transfer
 *
 */
void loopSerialTransfer();

#endif  // SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_
