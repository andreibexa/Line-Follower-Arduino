#ifndef SRC_JADE_UNOPLUS_LED_MATRIX_LED_MATRIX_H_
#define SRC_JADE_UNOPLUS_LED_MATRIX_LED_MATRIX_H_
#include "jade_unoplus/pins_jade_unoplus.h"
#include <Arduino.h>
#include <LedControl.h>

void loopMatrix();
void printByte(byte character[]);
void setupMatrix();

#endif  // SRC_JADE_UNOPLUS_LED_MATRIX_LED_MATRIX_H_
