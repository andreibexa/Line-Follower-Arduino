#include <Arduino.h>
#include "esp32/cloud_callback/cloud_callback.h"

bool line_follower_mode = false;

/*
  Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
*/
void onLineFollowerModeChange()
{
  Serial.print("line_follower_mode ");
  Serial.println(line_follower_mode);
}

/**
 * @brief Reset cloud variables
 *

 */
void resetCloudVariables()
{
  line_follower_mode = false;
}
