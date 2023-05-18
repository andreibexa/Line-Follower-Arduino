#include <Arduino.h>
#include "../include/pins_line_follower.h"

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

  // IR Infrared Line Follower Sensor
  pinMode(13, INPUT);
  pinMode(12, INPUT);
  pinMode(11, INPUT);
  pinMode(10, INPUT);
  pinMode(9, INPUT);
}

/**
 * @brief Power optimization. Set Arduino digital and analog pins to LOW
 *
 */
void setPinsLow()
{
  // Analog pins
  const uint8_t analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};

  // Set digital pins to LOW
  for (uint8_t i = 2; i < NUM_DIGITAL_PINS; i++)
  {
    digitalWrite(i, LOW);
  }

  // Set analog pins to LOW
  for (uint8_t i = 0; i < sizeof(analogPins) / sizeof(analogPins[0]); i++)
  {
    analogWrite(analogPins[i], LOW);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  setPinsMode();
  setPinsLow();
}
