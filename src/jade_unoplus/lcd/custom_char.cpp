
#include "jade_unoplus/lcd/custom_char.h"

// Cloud symbol
byte cloudConnectedStart[8] = { B00000, B00111, B01111, B11111,
                                B11111, B11111, B01111, B00000 };
byte cloudConnectedEnd[8] = { B00000, B11100, B11110, B11111,
                              B11111, B11111, B11110, B00000 };
byte cloudDisconnectedStart[8] = { B00010, B01111, B01010, B10010,
                                   B10010, B10010, B01111, B00010 };
byte cloudDisconnectedEnd[8] = { B01000, B11100, B01010, B01001,
                                 B01001, B01001, B11110, B01000 };


// 18650 battery symbol
byte battery18650[8] = { B00100, B01110, B01110, B01110,
                         B01110, B01110, B01110, B01110 };