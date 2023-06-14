#ifndef SRC_JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_
#define SRC_JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_
#include "transfer/enum_packet_id.h"
#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include "jade_unoplus/line_follower/line_follower.h"
#include "transfer/struct_line_follower_settings.h"
#include <SerialTransfer.h>
#include <SoftwareSerial.h>

extern SerialTransfer JadeTransfer;

/**
 * @brief Transmit the lineFollowerSettings
 *
 */
void transmitLineFollowerSettings();

/**
 * @brief Receive the lineFollowerSettings
 *
 */
void receiveLineFollowerSettings();

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

#endif  // SRC_JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_
