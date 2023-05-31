#include <Arduino.h>
#include <limits.h>
#include <pins_line_follower.h>

/**
 * @brief Detects obstacles using an ultrasonic sensor and returns the distance.
 *
 * @return distance The distance in centimeters.
 */
float getDistance()
{
  static float distance;
  static unsigned long previousMillis = 0; // Variable to store the previous time
  const long interval = 50;                // Wait interval between measurements (in milliseconds)

  unsigned long currentMillis = millis(); // Get the current time

  // Check if the interval has passed
  if (currentMillis - previousMillis >= interval)
  {
    previousMillis = currentMillis; // Update the previous time

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
