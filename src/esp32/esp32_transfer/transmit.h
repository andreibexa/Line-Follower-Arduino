#ifndef ESP32_ESP32_TRANSFER_TRANSMIT_H_
#define ESP32_ESP32_TRANSFER_TRANSMIT_H_

#include "serial_transfer/struct_line_follower_settings.h"
#include "serial_transfer/struct_esp32_status.h"
#include "serial_transfer/serial_transfer.h"
#include "serial_transfer/enum_packet_id.h"
#include "esp32/thing_properties/thing_properties.h"

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
 * @brief Transmit the WiFi and Cloud status
 *
 */
void transmitESP32Status();

#endif  // ESP32_ESP32_TRANSFER_TRANSMIT_H_
