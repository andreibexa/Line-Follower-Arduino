#ifndef JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_

#include "jade_unoplus/obstacle_detector/obstacle_detector.h"
#include "jade_unoplus/line_follower/control_direction.h"
#include "jade_unoplus/multicolor_led/multicolor_led.h"
#include "jade_unoplus/jade_transfer/transmit.h"
#include "jade_unoplus/tone/tone.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

/**
 * @brief Run the Line Follower only if lineFollowerMode is true
 */
void loopLineFollower();

// Initialize the line follower settings with default values
void initializeLineFollowerSettings();

/**
 * @brief Run the Line Follower
 *
 */
void runLineFollower();

/**
 * @brief Check if finish line is detected
 *
 */
void checkFinishLine();

/**
 * @brief Stop Line Follower
 *
 */
void stopLineFollower();

/**
 * @brief Calculate the line position error using a PID control
 * algorithm.
 *
 */
void calculatePID();

/**
 * Out of line. Turn back to the last known position
 *
 * @param motorLeftSpeed
 * @param motorRightSpeed
 *
 */
void restorePosition(int16_t motorLeftSpeed, int16_t motorRightSpeed);

/**
 * @brief Reads the line position using the IR sensors.
 *
 */
void readLinePosition();

/**
 * @brief Avoids obstacles if the distance to an obstacle is less than the specified minimum distance
 *
 * @param minObstacleDistance The minimum distance threshold for obstacle avoidance
 */
void avoidObstacle(uint8_t minObstacleDistance);

/**
 * @brief Serial prints the line and motor positions.
 *
 * @param motorLeftSpeed
 * @param motorRightSpeed
 */
void SerialPrintPosition(uint16_t motorLeftSpeed, uint16_t motorRightSpeed);

/**
 * @brief Upload the line follower settings to ESP32
 *
 */
void uploadLineFollowerSettings();

#endif  // JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
