#ifndef PINS_JADE_UNOPLUS_H_
#define PINS_JADE_UNOPLUS_H_

#include <Arduino.h>
// Ultrasonic Sensor Module - HC-SR04
#define ULTRASONIC_TRIG_PIN 2  // TRIG
#define ULTRASONIC_ECHO_PIN 3  // ECHO

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 5   // M1(A) - PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 6  //  M1(B) - PWM PIN

#define MOTOR_LEFT_FORWARD_PIN 9    // M2(A) - PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 10  // M2(B) - PWM PIN

// Serial RX and TX
#define TX_PIN 11  // TX PIN
#define RX_PIN 12  // RX PIN

// 3 Channel Red IR Infrared Tracking Sensor Module - CTRT5000
#define IR_TRACKING_SENSOR_RIGHT_PIN A3   // OTL
#define IR_TRACKING_SENSOR_CENTER_PIN A4  // OTC
#define IR_TRACKING_SENSOR_LEFT_PIN A5    // OTR

// LED Matrix display module - MAX7219
#define DIN A0
#define CLK A2
#define CS A1

#endif  // PINS_JADE_UNOPLUS_H_
