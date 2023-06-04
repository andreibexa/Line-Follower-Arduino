#ifndef SRC_JADE_UNOPLUS_COMMANDER_HANDLER_H_
#define SRC_JADE_UNOPLUS_COMMANDER_HANDLER_H_

#include "jade_unoplus/commander/commander.h";
Commander cmd;

/**
 * @brief Command handler to change the Line Follower mode
 *
 * @param Cmdr
 * @return true
 * @return false
 */
bool lineFollowerModeHandler(Commander &Cmdr)
{
  uint8_t enable = 0;

  // get the first argument
  Cmdr.getInt(enable);
  if (enable)
    enableLineFollowerMode();
  else
  {
    disableLineFollowerMode();
  }

  return 0;
}

// The command handler list for Serial Commander
const commandList_t commands[] = {
    {"line_follower_mode", lineFollowerModeHandler, "Change the Line Follower mode"},
};
#endif // SRC_JADE_UNOPLUS_COMMANDER_HANDLER_H_
