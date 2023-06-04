#ifndef SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_
#define SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_

#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/commander/commander.h"

/**
 * @brief Change the Line Follower mode
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool lineFollowerModeHandler(Commander &Cmdr)
{
  uint8_t argument = 0;

  // get the first argument
  Cmdr.getInt(argument);
  if (argument)
    enableLineFollowerMode();
  else
  {
    disableLineFollowerMode();
  }

  return 0;
}

/**
 * @brief min_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool minSpeedHandler(Commander &Cmdr)
{
  uint8_t argument = 0;

  // get the first argument
  Cmdr.getInt(argument);
  eeprom_settings.min_speed = argument;
  saveSettingsToEEPROM();

  return 0;
}

/**
 * @brief base_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool baseSpeedHandler(Commander &Cmdr)
{
  uint8_t argument = 0;

  // get the first argument
  Cmdr.getInt(argument);
  eeprom_settings.base_speed = argument;
  saveSettingsToEEPROM();

  return 0;
}

/**
 * @brief max_speed handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool maxSpeedHandler(Commander &Cmdr)
{
  uint8_t argument = 0;

  // get the first argument
  Cmdr.getInt(argument);
  eeprom_settings.max_speed = argument;
  saveSettingsToEEPROM();

  return 0;
}

/**
 * @brief kp handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool kpHandler(Commander &Cmdr)
{
  uint8_t argument = 0;

  // get the first argument
  Cmdr.getInt(argument);
  eeprom_settings.kp = argument;
  saveSettingsToEEPROM();

  return 0;
}

/**
 * @brief Print EEPROM settings handler
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool printSettingsHandler(Commander &Cmdr)
{
  printEEPROMSettings();

  return 0;
}

// The command handler list for Serial Commander
const commandList_t commands[] = {
    {"line_follower_mode", lineFollowerModeHandler, "Line Follower mode (Enable/Disable)"},
    {"min_speed", minSpeedHandler, "Min speed"},
    {"base_speed", baseSpeedHandler, "Base speed"},
    {"max_speed", maxSpeedHandler, "Max speed"},
    {"kp", kpHandler, "Kp factor for PID algorithm"},
    {"Print settings", printSettingsHandler, "Print eeprom settings"},
};
#endif // SRC_JADE_UNOPLUS_COMMANDER_SERIAL_HANDLER_H_
