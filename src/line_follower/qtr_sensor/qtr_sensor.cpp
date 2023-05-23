#include <QTRSensors.h>
#include <pins_line_follower.h>
#include "line_follower/qtr_sensor/qtr_sensor.h"

// QTRSensors library - https://pololu.github.io/qtr-sensors-arduino/md_usage.html
QTRSensors qtr;

const uint8_t QTR_SENSOR_COUNT = 5;
uint16_t QTR_SENSOR_VALUES[QTR_SENSOR_COUNT];

/**
 * @brief Setup the QTR sensor
 *
 */
void SetupQTRSensor()
{
  // Initialize the sensors.
  // We have 5 QTR sensors .
  qtr.setTypeAnalog();
  qtr.setSensorPins((const uint8_t[]){
                        QTR_LEFT_EDGE_PIN,
                        QTR_LEFT_MIDDLE_PIN,
                        QTR_MIDDLE,
                        QTR_RIGHT_MIDDLE_PIN,
                        QTR_RIGHT_EDGE_PIN},
                    QTR_SENSOR_COUNT);
}
