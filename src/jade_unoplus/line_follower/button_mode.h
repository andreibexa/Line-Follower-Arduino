#ifndef JADE_UNOPLUS_LINE_FOLLOWER_BUTTON_MODE_H_
#define JADE_UNOPLUS_LINE_FOLLOWER_BUTTON_MODE_H_
#include <Arduino.h>
#include "serial_transfer/struct_line_follower_settings.h"
#include "jade_unoplus/multicolor_led/multicolor_led.h"
#include "jade_unoplus/line_follower/line_follower.h"
/**
 * @brief Debounce the line follower mode on button pushup
 *
 */
void debounceLineFollowerButton();

#endif  // JADE_UNOPLUS_LINE_FOLLOWER_BUTTON_MODE_H_
