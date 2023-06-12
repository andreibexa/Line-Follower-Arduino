#ifndef SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
#define SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_

#include "jade_unoplus/jade_transfer/jade_transfer.h"
#include "jade_unoplus/line_follower/control_direction.h"
#include "jade_unoplus/obstacle_detector/obstacle_detector.h"
#include "jade_unoplus/pins_jade_unoplus.h"
#include "line_follower_struct_settings.h"
#include <Arduino.h>
#include <SoftwareSerial.h>

// Default values for line follower settings
#define DEFAULT_MODE false
#define DEFAULT_MIN_SPEED 0
#define DEFAULT_BASE_SPEED 180
#define DEFAULT_MAX_SPEED 255
#define DEFAULT_KP 0.40

// Function to initialize the line follower settings with default values
void initializeLineFollowerSettings();

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
 * @brief This function calculate the line position error using a PID control
 * algorithm.
 *
 */
void calculatePID(uint16_t currentPosition);

/**
 * Out of line. Turn back to the last known position
 *
 */
void restorePosition(int16_t motorLeftSpeed, int16_t motorRightSpeed);

/**
 * @brief Reads the line position using the IR sensors.
 *
 * @return Position value (500, 1000, 1500)
 */
uint16_t readLinePosition();

/**
 * @brief Avoid obstacle
 *
 * @param minObstacleDistance Avoid obstacle if the distance is less than
 * minObstacleDistance
 */
void avoidObstacle(uint8_t minObstacleDistance);

/**
 * @brief Serial prints the line and motor positions.
 *
 */
void SerialPrintPosition(
  uint16_t currentPosition, int16_t motorLeftSpeed, int16_t motorRightSpeed);

/**
 * @brief Upload the line follower settings to ESP32
 *
 */
void uploadLineFollowerSettings();

#endif  // SRC_JADE_UNOPLUS_LINE_FOLLOWER_LINE_FOLLOWER_H_
