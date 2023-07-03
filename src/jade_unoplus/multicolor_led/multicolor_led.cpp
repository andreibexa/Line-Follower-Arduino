#include "jade_unoplus/multicolor_led/multicolor_led.h"

bool ledBlink = false;
uint8_t ledColorRed = 0;
uint8_t ledColorGreen = 0;
uint8_t ledColorBlue = 0;

/**
 * @brief Multicolor LED loop called in the main loop
 *
 */
void loopMultiColorLed() {
  toggleLedBlink();
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

  changePINvalue(r, g, b);
}

/*
* @brief Toggle the multicolor led blink
*
*/
void toggleLedBlink() {
  if (ledBlink == false) {
    return;
  }

  unsigned long currentTime = millis();
  static unsigned long startTime = currentTime;
  static bool isLedOn = false;

  if (currentTime - startTime >= 600) {

    isLedOn = !isLedOn;
    // Turn off the LED for 600ms
    if (isLedOn) {
      changePINvalue(LOW, LOW, LOW);
    } else {
      changePINvalue(ledColorRed, ledColorGreen, ledColorBlue);
    }

    startTime = currentTime;
  }
}
