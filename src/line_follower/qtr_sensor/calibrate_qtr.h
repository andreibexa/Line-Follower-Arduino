#ifndef SRC_LINE_FOLLOWER_QTR_SENSOR_CALIBRATE_QTR_H_
#define SRC_LINE_FOLLOWER_QTR_SENSOR_CALIBRATE_QTR_H_

#include <stdint.h>

/**
 * @brief Calibrates the QTR sensor for the line follower.
 *        This function performs the necessary calibration steps
 *        to ensure accurate line detection.
 *
 *        During this calibration phase, you will need to expose each of
 *        your reflectance sensors to the lightest and darkest readings they will encounter
 *
 */
void InitializeQTRCalibration();

/**
 * @brief This function slide the QTR sensor in different directions.
 *
 */
void SlideQTRSensor();

/**
 * @brief Perform calibration iterations to update the sensor calibration.
 *
 * @param iterations The number of iterations to perform.
 */
void performCalibration(uint16_t iterations);

/**
 * @brief Prints the calibration values for the QTR sensors.
 *
 * This function prints the minimum and maximum calibration values
 * measured for each QTR sensor. The minimum values represent the
 * darkest readings, while the maximum values represent the lightest
 * readings obtained during calibration.
 */
void printQTRCalibrationValue();

#endif // SRC_LINE_FOLLOWER_QTR_SENSOR_CALIBRATE_QTR_H_
