#include "jade_unoplus/line_follower/button_mode.h"

// Current button state
int buttonState;
// Previous button state
int lastButtonState;
// Time of last button state change
unsigned long lastDebounceTime = 0;
// Debounce time in milliseconds
const unsigned long debounceDelay = 50;

/**
 * @brief Debounce the line follower mode on button pushup
 *
 */
void debounceLineFollowerButton() {
  // Read the current button state
  int reading = digitalRead(LINE_FOLLOWER_BUTTON_PIN);

  // Check for button state change with debounce
  if (reading != lastButtonState) {
    // Update the time of last button state change
    lastDebounceTime = millis();
  }

  // Check if enough debounce time has passed
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // Check if the button state has actually changed
    if (reading != buttonState) {
      buttonState = reading;

      // Only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        // Button was pressed
        lineFollowerSettings.lineFollowerMode = !lineFollowerSettings.lineFollowerMode;
      }
    }
  }

  // Update the previous button state
  lastButtonState = reading;
}
