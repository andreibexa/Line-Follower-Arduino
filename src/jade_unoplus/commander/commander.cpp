#include "jade_unoplus/commander/commander.h"
#include "jade_unoplus/commander/serial_handler.h"

Commander cmd;

/**
 * @brief Initialize Serial Commander
 *
 */
void setup_serial_commander()
{
  // Enable the command prompt
  cmd.commandPrompt(ON);

  //  Start Commander on Serial
  cmd.begin(&Serial, commands, sizeof(commands));

  // Echo incoming characters to theoutput port
  cmd.echo(true);

  cmd.printUserString();
  cmd.println();
  Serial.println("Type 'help' to get help");
  cmd.printCommandPrompt();
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
