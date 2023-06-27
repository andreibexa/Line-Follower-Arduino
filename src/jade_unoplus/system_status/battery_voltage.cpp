#include "jade_unoplus/system_status/battery_voltage.h"

/**
 * @brief Read the Vcc voltage from the internal 1.1V reference
 *
 * @return uint16_t
 */
uint16_t readBoardBatteryVoltage() {
  uint16_t result;

  // Set reference voltage to AVcc
  // Read "1.1V" reference against AREF
  ADMUX = _BV(REFS0) | _BV(MUX3) | _BV(MUX2) | _BV(MUX1);

  // Wait for Vref to settle
  delay(2);

  // Start ADC conversion
  ADCSRA |= _BV(ADSC);

  // Wait for conversion to complete
  while (bit_is_set(ADCSRA, ADSC)) { ; }

  // Read ADC result
  result = ADCL;
  result |= ADCH << 8;

  // Calculate AVcc in mV
  result = 1126400L / result;

  return result;
}

/**
 * @brief Read the H Bridge battery voltage using the voltage divider
 *
 * @return float
 */
float readAAbatteryVoltage() {
  float vin = 0.0;
  float vout = 0.0;
  float r1 = 9810.0;
  float r2 = 9780.0;

  // Read the AA voltage
  uint16_t analog_value = analogRead(AA_BATTERY_VOLTAGE_PIN);

  // Conversion formula
  vout = (analog_value * 4.77) / 1024.0;
  vin = vout / (r2 / (r1 + r2));
  if (vin < 0.1) {
    vin = 0.0;
  }

  return vin;
}
