#include <Arduino.h>
#include "line_follower/qtr_sensor/calibrate_qtr.h"
#include <line_follower/qtr_sensor/qtr_sensor.h>
#include "line_follower/control_direction.h"

/**
 * @brief Calibrates the QTR sensor for the line follower.
 *        This function performs the necessary calibration steps
 *        to ensure accurate line detection.
 *
 *        During this calibration phase, you will need to expose each of
 *        your reflectance sensors to the lightest and darkest readings they will encounter
 *
 */
void InitializeQTRCalibration()
{
  Serial.println("Calibration start");

  // Turn on Arduino's LED to indicate we are in calibration mode

  for (uint8_t i = 0; i < 1; i++)
  {
    // Slide the QTR sensor across the line during the calibration phase
    SlideQTRSensor();

    // read qtr sensor 40 times for each slide
    performCalibration(40);
  }

  Serial.println("Calibration ends");
}

/**
 * @brief This function slide the QTR sensor in different directions.
 *
 */
void SlideQTRSensor()
{
  uint8_t speed_forward = 88;
  uint8_t speed_backward = 78;
  uint16_t period = 490;

  controlDirection(RIGHT_WIDE_FORWARD, speed_forward, period);
  controlDirection(RIGHT_WIDE_BACKWARD, speed_backward, period);
  delay(500);
  controlDirection(LEFT_WIDE_FORWARD, speed_forward, period);
  controlDirection(LEFT_WIDE_BACKWARD, speed_backward, period);
  delay(500);
}

/**
 * @brief Perform calibration iterations to update the sensor calibration.
 *
 * @param iterations The number of iterations to perform.
 */
void performCalibration(uint16_t iterations)
{
  for (uint16_t i = 0; i < iterations; i++)
  {
    // Read the sensor values and update calibration
    qtr.calibrate();
  }
}

/**
 * @brief Prints the calibration values for the QTR sensors.
 *
 * This function prints the minimum and maximum calibration values
 * measured for each QTR sensor. The minimum values represent the
 * darkest readings, while the maximum values represent the lightest
 * readings obtained during calibration.
 */
void printQTRCalibrationValue()
{
  Serial.print("QTR sensor MIN values: ");
  for (uint8_t i = 0; i < QTR_SENSOR_COUNT; i++)
  {
    Serial.print(qtr.calibrationOn.minimum[i]);
    Serial.print(' ');
  }
  Serial.println();

  Serial.print("QTR sensor MAX values: ");
  // print the calibration maximum values measured when emitters were on
  for (uint8_t i = 0; i < QTR_SENSOR_COUNT; i++)
  {
    Serial.print(qtr.calibrationOn.maximum[i]);
    Serial.print(' ');
  }
  Serial.println();
  Serial.println();
  delay(1000);
}
