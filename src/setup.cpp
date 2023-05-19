#include <pins_line_follower.h>
#include "line_follower/qtr_sensor/qtr_sensor.h"
#include "line_follower/qtr_sensor/calibrate_qtr.h"

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

  // QTR Infrared Line Follower Sensor
  pinMode(QTR_LEFT_EDGE_PIN, INPUT);
  pinMode(QTR_LEFT_MIDDLE_PIN, INPUT);
  pinMode(QTR_MIDDLE, INPUT);
  pinMode(QTR_RIGHT_MIDDLE_PIN, INPUT);
  pinMode(QTR_RIGHT_EDGE_PIN, INPUT);
}

void setup()
{

  // Put your setup code here, to run once:
  Serial.begin(9600);

  // Disable Arduino builtin led
  digitalWrite(LED_BUILTIN, LOW);

  // SET pins mode OUTPUT/INPUT
  setPinsMode();

  // Setup the line follower QTR sensor
  SetupQTRSensor();

  InitializeQTRCalibration();
  printQTRCalibrationValue();
}
