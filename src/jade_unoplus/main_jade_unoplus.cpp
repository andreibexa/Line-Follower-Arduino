#include "jade_unoplus/eeprom_data/eeprom_data.h"
#include "jade_unoplus/jade_transfer/jade_transfer.h"
#include "jade_unoplus/line_follower/line_follower.h"
#include "jade_unoplus/line_follower/button_mode.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

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

  // Line follower pushup button (On/Off)
  // Enable the internal pull-up resistor
  pinMode(LINE_FOLLOWER_MODE_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(LINE_FOLLOWER_MODE_PIN), toggleLineFollowerMode, CHANGE);
}

/**
 * @brief Arduino setup function
 *
 */
void setup() {
  // Put your setup code here, to run once:
  Serial.begin(115200);

  // Initialize line follower settings with default settings
  initializeLineFollowerSettings();

  // setup the Jade UnoPlus Serial Transfer
  setupSerialTransfer();

  // Initialize EEPROM
  initializeEEPROM();

  // SET pins mode INPUT/OUTPUT
  setPinsMode();
}

/**
 * @brief Arduino main loop
 *`
 */
void loop() {

  // Serial Transfer loop
  loopSerialTransfer();

  // Line follower loop
  loopLineFollower();
}
