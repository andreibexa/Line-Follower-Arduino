#include <Arduino.h>
#include <pins_line_follower.h>
#include "line_follower/qtr_sensor/qtr_sensor.h"
#include "line_follower/line_follower.h"

/**
 * @brief Arduino main loop
 *`
 */
void loop()
{
  activateLineFollowerMode();

  // do nothing while serial is connected
}
