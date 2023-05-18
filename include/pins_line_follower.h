#ifndef PINS_LINE_FOLLOWER_H_
#define PINS_LINE_FOLLOWER_H_

// Dual-Channel H-Bridge Motor Driver Module - L9110S
#define MOTOR_RIGHT_FORWARD_PIN 3  // M1(A) / PWM PIN
#define MOTOR_RIGHT_BACKWARD_PIN 2 //  M1(B)

#define MOTOR_LEFT_FORWARD_PIN 5  // M2(A) / PWM PIN
#define MOTOR_LEFT_BACKWARD_PIN 4 // M2(B)

// IR Infrared Line Follower Sensor - TCRT5000
#define IR_LEFT_EDGE_PIN 13    // S1
#define IR_LEFT_MIDDLE_PIN 12  // S2
#define IR_CENTER 11           // S3
#define IR_RIGHT_MIDDLE_PIN 10 // S4
#define IR_RIGHT_EDGE_PIN 9    // S5

#endif // PINS_LINE_FOLLOWER_H_
