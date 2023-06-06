#ifndef SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_


/**
 * @brief Enable Line Follower mode
 *
 */
void enableLineFollowerMode();

/**
 * @brief Disable the Line Follower mode
 *
 */
void disableLineFollowerMode();

/**
 * @brief This function calculate the line position error using a PID control algorithm.
 *
 */
void calculatePID(uint16_t current_position);

/**
 * Out of line. Turn back to the last known position
 *
 */
void restorePosition(int16_t motor_left_speed, int16_t motor_right_speed);

/**
 * @brief Reads the line position using the IR sensors.
 *
 * @return Position value (500, 1000, 1500)
 */
uint16_t readLinePosition();

/**
 * @brief Avoid obstacle
 *
 * @param min_obstacle_distance Avoid obstacle if the distance is less than min_obstacle_distance
 */
void avoidObstacle(uint8_t min_obstacle_distance);

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(uint16_t current_position, int16_t motor_left_speed, int16_t motor_right_speed);

#endif // SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
