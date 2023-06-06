#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/commander/commander_handler.h"
#include <Commander.h>

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
  float argument = 0;

  // get the first argument
  Cmdr.getFloat(argument);
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
