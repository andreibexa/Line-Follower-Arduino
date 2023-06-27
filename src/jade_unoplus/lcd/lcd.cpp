#include "jade_unoplus/lcd/lcd.h"

// Set the LCD address to 0x27 for a 16 chars and 2 line display
LiquidCrystal_I2C lcd(0x27, 20, 2);

#define printByte(args) write(args)

/**
 * @brief Setup LCD
 *
 */
void setupLCD() {
  // Initialize the lcd
  lcd.init();
  lcd.setBacklight(5);

  // Custom lcd characters. Maximum 8 allowed
  lcd.createChar(0, battery18650);
  lcd.createChar(1, cloudDisconnectedStart);
  lcd.createChar(2, cloudDisconnectedEnd);
  lcd.createChar(3, cloudConnectedStart);
  lcd.createChar(4, cloudConnectedEnd);
}

/**
 * @brief Display the disconnected Wi-Fi message on the LCD
 *
 */
void displayWiFiDisconnected() {
  lcd.setCursor(0, 0);
  lcd.print("RSSI:n/a");
}


/**
 * @brief Display the WiFi signal strength on the LCD
 *
 * @param signalStrength The WiFi signal strength in dBm (-50 maximum, -100 lowest)
 */
void displayWiFiConnected(int signalStrength) {
  // Maximum number of signal bars
  uint8_t maxBars = 5;

  // Calculate the number of signal bars based on signal strength
  uint8_t bar = map(signalStrength, -100, -50, 0, maxBars);

  lcd.setCursor(0, 0);
  lcd.print("RSSI:");
  lcd.print(signalStrength);
  lcd.print("dBm");
}

/**
 * @brief Display the disconnected Cloud symbol on the LCD
 *
 */
void charCloudDisconnected() {
  lcd.setCursor(14, 0);
  lcd.printByte(1);
  lcd.setCursor(15, 0);
  lcd.printByte(2);
}

/**
 * @brief Display the connected Cloud symbol on the LCD
 *
 */
void charCloudConnected() {
  lcd.setCursor(14, 0);
  lcd.printByte(3);
  lcd.setCursor(15, 0);
  lcd.printByte(4);
}

/**
 * @brief Display the 18650 battery symbol on the LCD
 *
 */
void char18650Battery() {
  lcd.printByte(0);
}

/**
 * @brief Display the battery voltage on the LCD
 *
 * @param boardBatteryVoltage The battery voltage in mV
 *
 */
void display18650BatteryVoltage(uint16_t boardBatteryVoltage) {
  String voltageString = String(boardBatteryVoltage);


  lcd.setCursor(0, 1);
  char18650Battery();
  lcd.print(voltageString.charAt(0));
  lcd.print(".");
  lcd.print(voltageString.charAt(1));
  lcd.print(voltageString.charAt(2));
  lcd.print("v");
}


/**
 * @brief Display the AA battery voltage on LCD
 *
 * @param aaBatteryVoltage The battery voltage in mV
 *
 */
void displayAAbatteryVoltage(float aaBatteryVoltage) {
  lcd.setCursor(8, 1);
  lcd.print("AA:");

  lcd.print(aaBatteryVoltage, 2);
  lcd.print("v");
}