#ifndef SRC_ESP32_CLOUD_CALLBACK_CLOUD_CALLBACK_H_
#define SRC_ESP32_CLOUD_CALLBACK_CLOUD_CALLBACK_H_

extern bool line_follower_mode;

/**
 * @brief Since LineFollowerMode is READ_WRITE variable, onLineFollowerModeChange() is
  executed every time a new value is received from IoT Cloud.
 *
 */
void onLineFollowerModeChange();

/**
 * @brief Reset cloud variables
 *

 */
void resetCloudVariables();
#endif // SRC_ESP32_CLOUD_CALLBACK_CLOUD_CALLBACK_H_
