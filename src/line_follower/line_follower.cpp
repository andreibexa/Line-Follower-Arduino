#include <Arduino.h>
#include "../../include/pins_line_follower.h"
#include "line_follower/line_follower.h"

/**
 * @brief Initialize Line follower
 *
 */
void activateLineFollowerMode()
{
  setIrInfraredSensors(HIGH);
}

/**
 * @brief Disable the Line follower mode
 * ? Should i disable more pins
 */
void deactivateLineFollowerMode()
{
  // !TODO(my_username): call motorStopFunction()
  setIrInfraredSensors(LOW);
}

/**
 * @brief Set the pin value of IR Infrared sensors to LOW or HIGH
 *
 * @param val The pin value (LOW or HIGH).
 */

void setIrInfraredSensors(uint8_t val)
{
  // Set IR Infrared Sensor to LOW level
  digitalWrite(IR_LEFT_EDGE_PIN, val);
  digitalWrite(IR_LEFT_MIDDLE_PIN, val);
  digitalWrite(IR_CENTER, val);
  digitalWrite(IR_RIGHT_MIDDLE_PIN, val);
  digitalWrite(IR_RIGHT_EDGE_PIN, val);
}
