#include <Arduino.h>
#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/jade_transfer/jade_transfer.h"
#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/line_follower/button_mode.h"
#include "jade_unoplus/multicolor_led/multicolor_led.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include "jade_unoplus/lcd/lcd.h"
#include "jade_unoplus/system_status/system_status.h"


/**
 * @brief Set pin mode for the Jade Uno+ board
 *
 */
void setPinsMode() {
  // Dual-Channel H-Bridge Motor Driver Module
  pinMode(MOTOR_RIGHT_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_RIGHT_BACKWARD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_FORWARD_PIN, OUTPUT);
  pinMode(MOTOR_LEFT_BACKWARD_PIN, OUTPUT);

  // IR Infrared Line Follower Sensor Module
  pinMode(IR_TRACKING_SENSOR_LEFT_PIN, INPUT);
  pinMode(IR_TRACKING_SENSOR_CENTER_PIN, INPUT);
  pinMode(IR_TRACKING_SENSOR_RIGHT_PIN, INPUT);

  // Ultrasonic Sensor Module
  pinMode(ULTRASONIC_TRIG_PIN, OUTPUT);
  pinMode(ULTRASONIC_ECHO_PIN, INPUT);

  // Multicolor led
  pinMode(RED_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);
  pinMode(BLUE_PIN, OUTPUT);

  // Line follower pushup button (On/Off)
  pinMode(LINE_FOLLOWER_BUTTON_PIN, INPUT);
}

/**
 * @brief Arduino setup function
 *
 */
void setup() {
  // Put your setup code here, to run once:
  Serial.begin(115200);

  // Set the pins mode
  setPinsMode();

  // Initialize line follower settings with default settings
  initializeLineFollowerSettings();

  // Initialize EEPROM
  initializeEEPROM();

  // Serial Transfer setup
  setupSerialTransfer();

  // LCD setup
  setupLCD();

  // System status setup
  setupSystemStatus();
}

/**
 * @brief Arduino main loop
 *`
 */
void loop() {

  // Multicolor LED loop
  loopMultiColorLed();

  // Serial Transfer loop
  loopSerialTransfer();

  // Debounce the line follower mode on button pushup
  debounceLineFollowerButton();

  // Line follower loop
  loopLineFollower();

  // System status loop
  loopSystemStatus();
}
