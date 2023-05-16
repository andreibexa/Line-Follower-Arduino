#include <Arduino.h>
#include <pins_line_follower.h>
#include <directions.h>

unsigned long motor_running_time;
unsigned long current_time;

void initDirections()
{
  pinMode(HB_M_1A, OUTPUT);
  pinMode(HB_M_1B, OUTPUT);
  pinMode(HB_M_2A, OUTPUT);
  pinMode(HB_M_2B, OUTPUT);
}

void controlDirection(int direction, int speed)
{
  switch (direction)
  {
  case STOP_SLOW:
    // STOP Slow
    digitalWrite(HB_M_1A, LOW);
    digitalWrite(HB_M_1B, LOW);
    digitalWrite(HB_M_2A, LOW);
    digitalWrite(HB_M_2B, LOW);
    break;
  case STOP_FAST:
    // STOP Fast
    digitalWrite(HB_M_1A, HIGH);
    digitalWrite(HB_M_1B, HIGH);
    digitalWrite(HB_M_2A, HIGH);
    digitalWrite(HB_M_2B, HIGH);
    break;
  case FORWARD_FAST:
    // Forward
    digitalWrite(HB_M_1A, HIGH);
    digitalWrite(HB_M_1B, LOW);
    digitalWrite(HB_M_2A, HIGH);
    digitalWrite(HB_M_2B, LOW);
    break;
  case FORWARD_SLOW:
    // Forward Slow
    digitalWrite(HB_M_1A, HIGH);
    analogWrite(HB_M_1B, 255 - speed);
    digitalWrite(HB_M_2A, HIGH);
    analogWrite(HB_M_2B, 255 - speed);
    break;
  case REVERSE_FAST:
    // Reverse
    digitalWrite(HB_M_1A, LOW);
    digitalWrite(HB_M_1B, HIGH);
    digitalWrite(HB_M_2A, LOW);
    digitalWrite(HB_M_2B, HIGH);
    break;
  case RIGHT_WIDE:
    // Right Wide
    digitalWrite(HB_M_1A, LOW);
    digitalWrite(HB_M_1B, LOW);
    digitalWrite(HB_M_2A, HIGH);
    digitalWrite(HB_M_2B, LOW);
    break;
  case RIGHT_TIGHT:
    // Right Tight
    digitalWrite(HB_M_1A, LOW);
    digitalWrite(HB_M_1B, HIGH);
    digitalWrite(HB_M_2A, HIGH);
    digitalWrite(HB_M_2B, LOW);
    break;
  case LEFT_WIDE:
    // Left Wide
    digitalWrite(HB_M_1A, HIGH);
    digitalWrite(HB_M_1B, LOW);
    digitalWrite(HB_M_2A, LOW);
    digitalWrite(HB_M_2B, LOW);
    break;
  case LEFT_TIGHT:
    // Left Tight
    digitalWrite(HB_M_1A, HIGH);
    digitalWrite(HB_M_1B, LOW);
    digitalWrite(HB_M_2A, LOW);
    digitalWrite(HB_M_2B, HIGH);
    break;
  }
}

void setup()
{
  // put your setup code here, to run once:
  initDirections();
}

void loop()
{
  current_time = millis();

  /*   // move forward
    if (current_time - motor_running_time < 5000)
    {
      controlDirection(FORWARD_FAST, 255);
    } */

  // move left
  /* if (current_time - motor_running_time < 1000)
  {
    controlDirection(LEFT_TIGHT, 255);
  }
  else
  {
    motor_running_time = current_time;
  } */
  digitalWrite(HB_M_1A, HIGH);
  digitalWrite(HB_M_1B, LOW);

  delay(1000);

  digitalWrite(HB_M_1A, LOW);
}
