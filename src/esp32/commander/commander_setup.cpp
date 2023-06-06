#include "esp32/commander/commander_setup.h"

Commander cmd;

// The command handler list for Serial Commander
const commandList_t commands[] = {
    {"line_follower_mode", lineFollowerModeHandler, "Line Follower mode (Enable/Disable)"},
    {"min_speed", minSpeedHandler, "Min speed"},
    {"base_speed", baseSpeedHandler, "Base speed"},
    {"max_speed", maxSpeedHandler, "Max speed"},
    {"kp", kpHandler, "Kp factor for PID algorithm"},
};

/**
 * @brief Initialize Serial Commander
 *
 */
void setup_serial_commander()
{
  while (!Serial)
  {
    ;
  }
  initialiseCommander(); //  start Commander on Serial
  cmd.commandPrompt(ON); // enable the command prompt
  cmd.echo(true);        // Echo incoming characters to theoutput port
  Serial.println("Hello: Type 'help' to get help");
  cmd.printCommandPrompt();
}

/**
 * @brief Intialise Commander
 *
 */
void initialiseCommander()
{
  cmd.begin(&Serial, commands, sizeof(commands));
}

/**
 * @brief Loop serial commander
 *
 */
void loop_serial_commander()
{
  // put your main code here, to run repeatedly:
  cmd.update();
}
