#ifndef JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_
#define JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_

#include "jade_unoplus/jade_transfer/transmit.h"
#include "jade_unoplus/jade_transfer/receive.h"
#include <SoftwareSerial.h>


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

#endif  // JADE_UNOPLUS_JADE_TRANSFER_JADE_TRANSFER_H_
