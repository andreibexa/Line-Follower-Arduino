#ifndef JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_
#define JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_

#include <Arduino.h>

// #define PIN 2

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 3   // M1(A) - PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 4  //  M1(B)

#define MOTOR_LEFT_FORWARD_PIN 6    // M2(A) - PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 7   // M2(B)

// #define PIN 8

// Multicolor led
#define RED_PIN 5    // RED - PWM PIN
#define GREEN_PIN 9  // GREEN - PWM PIN
#define BLUE_PIN 10  // BLUE - PWM PIN

// Serial RX and TX
#define TX_PIN 11  // TX PIN
#define RX_PIN 12  // RX PIN

// Push up button to change line follower mode (On/Off)
#define LINE_FOLLOWER_BUTTON_PIN 13

// Ultrasonic Sensor Module - HC-SR04
#define ULTRASONIC_TRIG_PIN 22  // TRIG
#define ULTRASONIC_ECHO_PIN 23  // ECHO

// 3 Channel Red IR Infrared Tracking Sensor Module - CTRT5000
#define IR_TRACKING_SENSOR_LEFT_PIN A0    // OTL
#define IR_TRACKING_SENSOR_CENTER_PIN A1  // OTC
#define IR_TRACKING_SENSOR_RIGHT_PIN A2   // OTR

// AA Battery voltage divider
#define AA_BATTERY_VOLTAGE_PIN A7

// LCD Display 1602 + I2C
#define LCD_SDA_PIN A4  // SDA
#define LCD_SCL_PIN A5  // SCL

#endif                  // JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_
