#ifndef JADE_UNOPLUS_LCD_LCD_H_
#define JADE_UNOPLUS_LCD_LCD_H_

#include "jade_unoplus/lcd/custom_char.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

/**
 * @brief Setup LCD
 *
 */
void setupLCD();

/**
 * @brief Display the disconnected Wi-Fi  message on the LCD
 *
 */
void displayWiFiDisconnected();

/**
 * @brief Display the WiFi signal strength on the LCD
 *
 * @param signalStrength The WiFi signal strength in dBm (-50 maximum, -100 lowest)
 */
void displayWiFiConnected(int signalStrength);

/**
 * @brief Display the disconnected Cloud symbol on the LCD
 *
 */
void charCloudDisconnected();

/**
 * @brief Display the connected Cloud symbol on the LCD
 *
 */
void charCloudConnected();

/**
 * @brief Display the 18650 battery symbol on LCD
 *
 */
void char18650Battery();

/*
 * @brief Display the battery voltage on LCD
 *
 */
void display18650BatteryVoltage(uint16_t boardBatteryVoltage);

/**
 * @brief Display the battery voltage on LCD
 *
 * @param hBridgeBatteryVoltage The battery voltage in mV
 *
 */
void displayAAbatteryVoltage(float aaBatteryVoltage);

#endif  // JADE_UNOPLUS_LCD_LCD_H_
