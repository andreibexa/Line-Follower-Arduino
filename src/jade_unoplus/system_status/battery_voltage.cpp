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
  float Vin = 0.0;
  float Vout = 0.0;
  float r1 = 9810.0;
  float r2 = 9780.0;
  float boardVoltage = 4.77;

  // Read the AA voltage
  uint16_t analogValue = analogRead(AA_BATTERY_VOLTAGE_PIN);

  // Conversion formula
  Vout = (analogValue * boardVoltage) / 1024.0;
  Vin = Vout / (r2 / (r1 + r2));
  if (Vin < 0.1) {
    Vin = 0.0;
  }

  return Vin;
}
