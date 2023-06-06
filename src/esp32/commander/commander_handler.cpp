

#include "esp32/thingProperties.h"
#include "esp32/commander/commander_handler.h"
#include <Commander.h>

/**
 * @brief Update line_follower_mode
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
  line_follower_mode = argument;

  return 0;
}

/**
 * @brief Update min_speed
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
  min_speed = argument;

  return 0;
}

/**
 * @brief Update base_speed
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
  base_speed = argument;

  return 0;
}

/**
 * @brief Update max_speed
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
  max_speed = argument;

  return 0;
}

/**
 * @brief Update kp
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
  kp = argument;

  return 0;
}
