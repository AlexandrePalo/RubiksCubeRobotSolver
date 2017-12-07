/*
#include "msp.h"
#include "driverlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "colorUtils.h"
#include "colorSensor.h"


void main(void) {
    int t = 0;
    // Stop WDT
    MAP_WDT_A_holdTimer();

    // Init color sensor
    colorSensorInit();

    while (1) {
        for(t = 0; t < MEAS_DELAY; t++){}

        printf("color: %s\n", colorTextFromColorInt(getColorInt()));
    }
}
*/
