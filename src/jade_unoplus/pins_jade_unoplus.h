#ifndef JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_
#define JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_

#include <Arduino.h>
// Ultrasonic Sensor Module - HC-SR04
#define ULTRASONIC_TRIG_PIN 2  // TRIG
#define ULTRASONIC_ECHO_PIN 3  // ECHO

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 5   // M1(A) - PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 6  //  M1(B) - PWM PIN

// Push up button to change line follower mode (On/Off)
#define LINE_FOLLOWER_MODE_PIN 8

#define MOTOR_LEFT_FORWARD_PIN 9    // M2(A) - PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 10  // M2(B) - PWM PIN

// Serial RX and TX
#define TX_PIN 11  // TX PIN
#define RX_PIN 12  // RX PIN

// 3 Channel Red IR Infrared Tracking Sensor Module - CTRT5000
#define IR_TRACKING_SENSOR_RIGHT_PIN A0   // OTR
#define IR_TRACKING_SENSOR_CENTER_PIN A1  // OTC
#define IR_TRACKING_SENSOR_LEFT_PIN A2    // OTL

// Multicolor led
#define RED_PIN A7
#define GREEN_PIN A6
#define BLUE_PIN 23

#endif  // JADE_UNOPLUS_PINS_JADE_UNOPLUS_H_
