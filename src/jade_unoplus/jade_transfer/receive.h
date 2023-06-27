#ifndef JADE_UNOPLUS_JADE_TRANSFER_RECEIVE_H_
#define JADE_UNOPLUS_JADE_TRANSFER_RECEIVE_H_

#include "serial_transfer/struct_line_follower_settings.h"
#include "serial_transfer/struct_esp32_status.h"
#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/eeprom_data/eeprom_data.h"

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings();

/**
 * @brief Receive the ESP32 esp32Status
 *
 */
void receiveESP32Status();

#endif  // JADE_UNOPLUS_JADE_TRANSFER_RECEIVE_H_
