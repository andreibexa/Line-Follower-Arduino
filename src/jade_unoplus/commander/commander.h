#ifndef SRC_JADE_UNOPLUS_COMMANDER_COMMANDER_H_
#define SRC_JADE_UNOPLUS_COMMANDER_COMMANDER_H_
#include <Commander.h>
#include "jade_unoplus/commander/commander.h"
#include "jade_unoplus/line_follower/line_follower.h"

extern Commander cmd;

/**
 * @brief Initialize Serial Commander
 *
 */
void setup_serial_commander();

/**
 * @brief Loop serial commander
 *
 */
void loop_serial_commander();

#endif // SRC_JADE_UNOPLUS_COMMANDER_COMMANDER_H_
