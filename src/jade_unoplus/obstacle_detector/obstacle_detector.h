#ifndef SRC_JADE_UNOPLUS_OBSTACLE_DETECTOR_OBSTACLE_DETECTOR_H_
#define SRC_JADE_UNOPLUS_OBSTACLE_DETECTOR_OBSTACLE_DETECTOR_H_

#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>

/**
 * @brief Detects obstacles using an ultrasonic sensor and returns the distance.
 *
 * @return distance The distance in centimeters.
 */
float getDistance();
#endif  // SRC_JADE_UNOPLUS_OBSTACLE_DETECTOR_OBSTACLE_DETECTOR_H_
