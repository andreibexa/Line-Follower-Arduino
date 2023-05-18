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
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(A2, INPUT);
  pinMode(A3, INPUT);
  pinMode(A4, INPUT);
}

/**
 * @brief Power optimization. Set Arduino digital and analog pins to LOW
 *
 */
void setPinsLow()
{
  // Analog pins board
  const uint8_t analogPins[] = {A0, A1, A2, A3, A4, A5, A6, A7};

  // Set digital pins to LOW
  for (uint8_t i = 2; i < NUM_DIGITAL_PINS; i++)
  {
    digitalWrite(i, LOW);
  }

  /**
   * Set analog pins board to LOW
   *
   * STL algorithms and range-based for loops should be preferred to traditional for loops (cpp:S5566)
   */
  for (uint8_t PIN : analogPins)
  {
    analogWrite(PIN, LOW);
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);

  setPinsMode();
  setPinsLow();
}
