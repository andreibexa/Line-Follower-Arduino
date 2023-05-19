#ifndef PINS_LINE_FOLLOWER_H_
#define PINS_LINE_FOLLOWER_H_

#include <Arduino.h>

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 5  // M1(A) - PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 6 //  M1(B) - PWM PIN

#define MOTOR_LEFT_FORWARD_PIN 9   // M2(A) - PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 10 // M2(B) - PWM PIN

// QTR Infrared Line Follower Sensor - TCRT5000
#define QTR_LEFT_EDGE_PIN A0    // S1
#define QTR_LEFT_MIDDLE_PIN A1  // S2
#define QTR_MIDDLE A2           // S3
#define QTR_RIGHT_MIDDLE_PIN A3 // S4
#define QTR_RIGHT_EDGE_PIN A4   // S5

#endif // PINS_LINE_FOLLOWER_H_
