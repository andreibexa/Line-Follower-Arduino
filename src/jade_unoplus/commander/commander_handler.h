#ifndef SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_
#define SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_
#include <Commander.h>


/**
 * @brief Change the Line Follower mode
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool lineFollowerModeHandler(Commander &Cmdr);

/**
 * @brief min_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool minSpeedHandler(Commander &Cmdr);

/**
 * @brief base_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool baseSpeedHandler(Commander &Cmdr);

/**
 * @brief max_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool maxSpeedHandler(Commander &Cmdr);

/**
 * @brief kp handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool kpHandler(Commander &Cmdr);

/**
 * @brief Print EEPROM settings handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool printSettingsHandler(Commander &Cmdr);


#endif // SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_
