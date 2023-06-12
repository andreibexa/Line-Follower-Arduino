#ifndef SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_
#define SRC_ESP32_ESP32_TRANSFER_ESP32_TRANSFER_H_

#include "enum_packet_id.h"
#include "esp32/thing_properties/thing_properties.h"
#include "line_follower_struct_settings.h"
#include <SerialTransfer.h>

extern SerialTransfer ESP32Transfer;

/**
 * @brief Receive lineFollowerSettings
 *
 */
void receiveLineFollowerSettings();

/**
 * @brief  Transmit request to retrieve lineFollowerSettings
 *
 */
void requestLineFollowerSettings();

/**
 * @brief Transmit cloud data of the lineFollowerSettings
 *
 */
void transmitLineFollowerSettings();

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
