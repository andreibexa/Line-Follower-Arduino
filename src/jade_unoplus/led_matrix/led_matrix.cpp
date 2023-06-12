
#include "jade_unoplus/led_matrix/led_matrix.h"

#define NBR_MTX 0  // number of matrices attached is one

LedControl lc = LedControl(DIN, CLK, CS, NBR_MTX);
/* we always wait a bit between updates of the display */
unsigned long delaytime = 100;

byte cub1[] = {0xff, 0x81, 0xbd, 0xa5, 0xa5, 0xbd, 0x81, 0xff};

byte cub2[] = {0x00, 0x7e, 0x42, 0x5a, 0x5a, 0x42, 0x7e, 0x00};
byte cub3[] = {0x00, 0x00, 0x3c, 0x24, 0x24, 0x3c, 0x00, 0x00};
byte cub4[] = {0x00, 0x00, 0x00, 0x18, 0x18, 0x00, 0x00, 0x00};

// Setup the The MAX72XX (8x8)
void setupMatrix() {
    // The MAX72XX is in power-saving mode on startup, we have to do a wakeup
    // call
    lc.shutdown(0, false);
    /* Set the brightness to a medium value */
    lc.setIntensity(0, 5);
    /* and clear the display */
    lc.clearDisplay(0);
}

void printByte(byte character[]) {
    for (int i = 0; i < 8; i++) {
        lc.setRow(0, i, character[i]);
    }
}

void loopMatrix() {
    /* printByte(cub1);
    delay(200);
    printByte(cub2);
    delay(200);
    printByte(cub3);
    delay(200);
    printByte(cub4);
    delay(200); */
}
