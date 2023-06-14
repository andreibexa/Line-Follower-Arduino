#include "jade_unoplus/line_follower/button_mode.h"
#include "jade_unoplus/multicolor_led/multicolor_led.h"

/**
 * @brief Toggle the line follower mode on button pushup
 *
 */
void toggleLineFollowerMode() {
  lineFollowerSettings.lineFollowerMode = !lineFollowerSettings.lineFollowerMode;

  if (lineFollowerSettings.lineFollowerMode == 0) {
    // Red color
    setMultiColorLed(0, 51, 0);
  } else {
    // Green green
    setMultiColorLed(153, 51, 51);
  }
}
