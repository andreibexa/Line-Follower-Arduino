#ifndef JADE_UNOPLUS_MULTICOLOR_LED_MULTICOLOR_LED_H_
#define JADE_UNOPLUS_MULTICOLOR_LED_MULTICOLOR_LED_H_
#include <Arduino.h>
#include "jade_unoplus/pins_jade_unoplus.h"

/**
 * @brief Multicolor LED loop called in the main loop
 *
 */
void loopMultiColorLed();

/**
 * @brief Change multicolor led pins values
 *
 * This function sets the color of a RGB LED by adjusting the intensity of its red, green, and blue channels.
 *
 * @param r The intensity of the red channel (0-255).
 * @param g The intensity of the red channel (0-255).
 * @param b The intensity of the red channel (0-255).
 */
void changePINvalue(uint8_t r, uint8_t g, uint8_t b);

/**
 * @brief Set the multicolor led variables
 *
 * @param r The intensity of the red channel (0-255).
 * @param g The intensity of the red channel (0-255).
 * @param b The intensity of the red channel (0-255).
 * @param blink Blink (true or false)
 */
void setMultiColorLed(uint8_t r, uint8_t g, uint8_t b, bool blink = false);

/*
* @brief Toggle the multicolor led blink
*
*/
void toggleLedBlink();

#endif  // JADE_UNOPLUS_MULTICOLOR_LED_MULTICOLOR_LED_H_
