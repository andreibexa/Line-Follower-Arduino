#ifndef JADE_UNOPLUS_SYSTEM_STATUS_SYSTEM_STATUS_H_
#define JADE_UNOPLUS_SYSTEM_STATUS_SYSTEM_STATUS_H_
#include "jade_unoplus/multicolor_led/multicolor_led.h"
#include "jade_unoplus/lcd/lcd.h"
#include "jade_unoplus/system_status/battery_voltage.h"
#include "serial_transfer/struct_esp32_status.h"

/**
 * @brief Setup system status
 *
 */
void setupSystemStatus();

/**
 * @brief System status loop called in the main loop
 *
 */
void loopSystemStatus();

/**
 * @brief Handlde the system status based on the esp32Status
 *
 */
void handleStatusFromESP32();

/**
 * @brief Display the battery status on the LCD
 *
 */
void displayBatteryStatus();

/**
 * @brief Display the WiFi signal strength on the LCD
 *
 * @param signalStrength The WiFi signal strength in dBm (-50 maximum, -100 lowest)
 */
void displayWiFiSignal(int signalStrength);

#endif  // JADE_UNOPLUS_SYSTEM_STATUS_SYSTEM_STATUS_H_
