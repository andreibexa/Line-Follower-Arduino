#ifndef SRC_LINE_FOLLOWER_QTR_SENSOR_QTR_SENSOR_H_
#define SRC_LINE_FOLLOWER_QTR_SENSOR_QTR_SENSOR_H_

// Include QTR sensors library - https://pololu.github.io/qtr-sensors-arduino/md_usage.html
#include <QTRSensors.h>

extern QTRSensors qtr;

extern const uint8_t QTR_SENSOR_COUNT;
extern uint16_t QTR_SENSOR_VALUES[5];

/**
 * @brief Setup the QTR sensor
 *
 */
void SetupQTRSensor();

#endif // SRC_LINE_FOLLOWER_QTR_SENSOR_QTR_SENSOR_H_
