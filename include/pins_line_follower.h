#ifndef PINS_LINE_FOLLOWER_H_
#define PINS_LINE_FOLLOWER_H_

#include <Arduino.h>

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 5  // M1(A) - PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 6 //  M1(B) - PWM PIN

#define MOTOR_LEFT_FORWARD_PIN 9   // M2(A) - PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 10 // M2(B) - PWM PIN

// 3 Channel Red IR Infrared Tracking Tracing Sensor Module - CTRT5000
#define IR_TRACKING_SENSOR_RIGHT_PIN 11  // S1
#define IR_TRACKING_SENSOR_CENTER_PIN 12 // S2
#define IR_TRACKING_SENSOR_LEFT_PIN 13   // S3

// Ultrasonic Sensor Module - HC-SR04
#define ULTRASONIC_TRIG_PIN 2  // TRIG
#define ULTRASONIC_ECHO__PIN 3 // ECHO
#endif                         // PINS_LINE_FOLLOWER_H_
