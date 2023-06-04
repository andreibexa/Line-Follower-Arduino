#include <pins_jade_unoplus.h>
#include "commander/commander.h"
#include <EEPROM.h>

/**
 * @brief Initialize Pin Mode
 *
 */
void setPinsMode()
{
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
}

/**
 * @brief Arduino setup function
 *
 */
void setup()
{
  // Put your setup code here, to run once:
  Serial.begin(9600);

  // Wait for the serial port to open (if using USB)
  while (!Serial)
  {
    ;
  }
  Serial.println("Serial initialized");

  // SET pins mode OUTPUT/INPUT
  setPinsMode();

  // Initialize Serial Commander
  setup_serial_commander();
}
