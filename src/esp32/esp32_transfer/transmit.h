#ifndef ESP32_ESP32_TRANSFER_TRANSMIT_H_
#define ESP32_ESP32_TRANSFER_TRANSMIT_H_

#include "esp32/thing_properties/thing_properties.h"
#include "transfer/struct_line_follower_settings.h"

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

#endif  // ESP32_ESP32_TRANSFER_TRANSMIT_H_
