#include <Arduino.h>
#include <pins_jade_unoplus.h>
#include "jade_unoplus/commander/commander_setup.h"
#include <SoftwareSerial.h>
#include "jade_unoplus/SerialCommunication.h"
#include "jade_unoplus/led_matrix/led_matrix.h"

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

  // Setup SerialCom to communicate with ESP32
  SoftwareSerial SerialCom(RX_COM_PIN, TX_COM_PIN);
  SerialCom.begin(9600);

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

  // Matrix setup
  setup_matrix();
}

/**
 * @brief Arduino main loop
 *`
 */
void loop()
{
  // Loop serial commander
  loop_serial_commander();

  // Matrix loop
  loop_matrix();
}
