#include "jade_unoplus/obstacle_detector/obstacle_detector.h"

/**
 * @brief Detects obstacles using an ultrasonic sensor and returns the distance.
 *
 * @return distance The distance in centimeters.
 */
float getDistance() {
  float distance;

  // Get the current time
  unsigned long currentMillis = millis();
  static unsigned long previousMillis = 0;

  // Check if the interval has passed
  if (currentMillis - previousMillis >= 100) {
    previousMillis = currentMillis;

    // Send an ultrasonic signal
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);
    delayMicroseconds(2);
    digitalWrite(ULTRASONIC_TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(ULTRASONIC_TRIG_PIN, LOW);

    // Measure the duration of the ultrasonic signal's return
    unsigned long duration = pulseIn(ULTRASONIC_ECHO_PIN, HIGH);

    // Calculate the distance in centimeters
    // The speed of sound is approximately 0.0343 cm/microsecond
    distance = duration * 0.0343 / 2;
  }

  return distance;
}
