#include "jade_unoplus/multicolor_led/multicolor_led.h"

uint8_t ledColorRed = 0;
uint8_t ledColorGreen = 0;
uint8_t ledColorBlue = 0;
bool ledBlink = false;

/**
 * @brief Multicolor LED loop called in the main loop
 *
 */
void loopMultiColorLed() {
  unsigned long currentTime = millis();
  static unsigned long startTime = currentTime;

  if (ledBlink && (currentTime - startTime) >= 500) {
    // Turn off the LED for 500ms
    changePINvalue(0, 0, 0);
    startTime = currentTime;
  } else {
    // Turn on the LED with the defined RGB color
    changePINvalue(ledColorRed, ledColorGreen, ledColorBlue);
  }
}

/**
 * @brief Change multicolor led pins values
 *
 * This function sets the color of a RGB LED by adjusting the intensity of its red, green, and blue channels.
 *
 * @param r The intensity of the red channel (0-255).
 * @param g The intensity of the red channel (0-255).
 * @param b The intensity of the red channel (0-255).
 */
void changePINvalue(uint8_t r, uint8_t g, uint8_t b) {
  analogWrite(RED_PIN, r);
  analogWrite(GREEN_PIN, g);
  analogWrite(BLUE_PIN, b);
}

/**
 * @brief Set the multicolor led variables
 *
 * @param r The intensity of the red channel (0-255).
 * @param g The intensity of the red channel (0-255).
 * @param b The intensity of the red channel (0-255).
 * @param blink Blink (true or false)
 */
void setMultiColorLed(uint8_t r, uint8_t g, uint8_t b, bool blink) {
  ledColorRed = r;
  ledColorGreen = g;
  ledColorBlue = b;
  ledBlink = blink;
}
