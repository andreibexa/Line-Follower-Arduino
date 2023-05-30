#ifndef SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_

#include <Arduino.h>
#include <pins_line_follower.h>

/**
 * @brief Activate line follower mode
 *
 */
void activateLineFollowerMode();

/**
 * @brief Disable the Line follower mode
 *
 */
void deactivateLineFollowerMode();

/**
 * @brief This function calculate the line position error using a PID control algorithm.
 *
 */
void calculatePID(int current_position);

/**
 * Out of line. Turn back to the last known position
 *
 */
void restorePosition(uint8_t motor_left_speed, uint8_t motor_right_speed);

/**
 * @brief Reads the line position using the IR sensors.
 *
 * @return Position value (500, 1000, 1500)
 */
uint16_t readLinePosition();

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(uint16_t current_position, uint8_t motor_left_speed, uint8_t motor_right_speed);

#endif // SRC_LINE_FOLLOWER_LINE_FOLLOWER_H_
