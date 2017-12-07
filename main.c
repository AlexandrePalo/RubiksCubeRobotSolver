#include "msp.h"
#include "driverlib.h"
#include <stdio.h>
#include "workFlow.h"
#include "sensor/colorUtils.h"
#include "solver/mixxer.h"
#include "solver/tools.h"
#include "solver/stage1a.h"
#include "solver/stage1b.h"
#include "solver/validator.h"
#include "configCombination.h"
#include "servo/servoControl.h"
#include "configLEDsSwitches.h"
#include "steppers/steppersControl.h"

// DO NOT DECLARE THEM GLOBALLY BECAUSE CONFLIC WITH R IN DRIVERLIB
#define O ORANGE
#define W WHITE
#define G GREEN
#define B BLUE
#define R RED
#define Y YELLOW

// Parse cube here
// int cube[9][12] = ...
int cube[9][12] = {{8, 8, 8, Y, O, Y, 8, 8, 8, 8, 8, 8}, {8, 8, 8, W, O, G, 8, 8, 8, 8, 8, 8}, {8, 8, 8, B, O, O, 8, 8, 8, 8, 8, 8}, {R, O, W, O, B, Y, B, Y, O, G, G, G}, {W, G, W, R, Y, O, Y, B, R, Y, W, B}, {W, R, R, W, G, R, Y, B, B, W, R, G}, {8, 8, 8, G, W, B, 8, 8, 8, 8, 8, 8}, {8, 8, 8, B, R, Y, 8, 8, 8, 8, 8, 8}, {8, 8, 8, O, G, R, 8, 8, 8, 8, 8, 8}};

int cubeFromSight[9][12] = {{8, 8, 8, Y, O, O, 8, 8, 8, 8, 8, 8}, {8, 8, 8, G, O, B, 8, 8, 8, 8, 8, 8}, {8, 8, 8, W, G, B, 8, 8, 8, 8, 8, 8}, {R, O, G, O, W, W, O, R, Y, B, Y, G}, {O, G, R, W, Y, G, R, B, W, B, W, W}, {R, Y, Y, G, Y, R, W, O, Y, B, Y, W}, {8, 8, 8, O, R, G, 8, 8, 8, 8, 8, 8}, {8, 8, 8, B, R, B, 8, 8, 8, 8, 8, 8}, {8, 8, 8, B, G, R, 8, 8, 8, 8, 8, 8}};

void main(void) {
    int error = 0;
    int configDone = 0;
    int testMotorsDone = 1;
    int colorDetectionDone = 1;
    int solutionDone = 0;
    int executionDone = 0;

    // Configuration
    if (fullConfig() == 1) {
        configDone = 1;
    }

    int x; for (x=0; x<500000; x++) {}

    // Main loop
    while (1) {
        //goToLeftOfLine();
        //printRawColor();

        // Set LEDs according to state
        if (error == 1) {
            MAP_GPIO_setOutputHighOnPin(LED1_RED_PORT, LED1_RED_PIN);
            MAP_GPIO_setOutputHighOnPin(LED2_RED_PORT, LED2_RED_PIN);
            MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
            MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
        } else {
            if (configDone == 1) {
                if (colorDetectionDone == 1) {
                    if (solutionDone == 1) {
                        if (executionDone == 1) {
                            // Reset all
                            colorDetectionDone = 0;
                            solutionDone = 0;
                            executionDone = 0;
                            resetCombination();
                        } else {
                            // Waiting for user, solution done
                            MAP_GPIO_setOutputLowOnPin(LED1_RED_PORT, LED1_RED_PIN);
                            MAP_GPIO_setOutputLowOnPin(LED2_RED_PORT, LED2_RED_PIN);
                            MAP_GPIO_setOutputHighOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
                            MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
                        }
                    } else {
                        // Waiting for user, color detection only done
                        MAP_GPIO_setOutputLowOnPin(LED1_RED_PORT, LED1_RED_PIN);
                        MAP_GPIO_setOutputLowOnPin(LED2_RED_PORT, LED2_RED_PIN);
                        MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
                        MAP_GPIO_setOutputHighOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
                    }
                } else {
                    // Waiting for user, nothing done except config
                    MAP_GPIO_setOutputHighOnPin(LED1_RED_PORT, LED1_RED_PIN);
                    MAP_GPIO_setOutputLowOnPin(LED2_RED_PORT, LED2_RED_PIN);
                    MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
                    MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
                }
            }
        }


        // Switch 1 pressed, manual mode
        if(GPIO_INPUT_PIN_LOW == MAP_GPIO_getInputPinValue(SWITCH1_PORT, SWITCH1_PIN)) {
            // Do something ONLY IF no error
            if (error != 1) {
                // Processing LED indication
                MAP_GPIO_setOutputLowOnPin(LED1_RED_PORT, LED1_RED_PIN);
                MAP_GPIO_setOutputHighOnPin(LED2_RED_PORT, LED2_RED_PIN);
                MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
                MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);

                // Do something ONLY IF config is done.
                if (configDone == 1) {

                    // DEBUG ONLY
                    if (testMotorsDone != 1) {
                        int l;
                        realF();
                        realF();
                        for(l=0;l<50000;l++) {}
                        realFc();
                        realFc();
                        for(l=0;l<50000;l++) {}
                        realB();
                        realB();
                        for(l=0;l<50000;l++) {}
                        realBc();
                        realBc();
                        for(l=0;l<50000;l++) {}
                        realR();
                        realR();
                        for(l=0;l<50000;l++) {}
                        realRc();
                        realRc();
                        for(l=0;l<50000;l++) {}
                        realL();
                        realL();
                        for(l=0;l<50000;l++) {}
                        realLc();
                        realLc();
                        for(l=0;l<50000;l++) {}
                        realU();
                        realU();
                        for(l=0;l<50000;l++) {}
                        realUc();
                        realUc();
                        for(l=0;l<50000;l++) {}
                        realD();
                        realD();
                        for(l=0;l<50000;l++) {}
                        realDc();
                        realDc();
                        for(l=0;l<50000;l++) {}

                        testMotorsDone = 1;
                    }

                    if (colorDetectionDone == 1) {
                        if (solutionDone == 1) {
                            if (executionDone == 1) {
                                // Nothing to do, this step should not occurs
                                // Reset all to be sure
                            } else {
                                if (executeCube() == 1) {
                                    executionDone = 1;
                                } else {
                                    error = 1;
                                }
                            }
                        } else {
                            if (solveCube(cube) == 1) {
                                solutionDone = 1;
                            } else {
                                error = 1;
                            }
                        }
                    } else {
                        if (detectCube(cube, cubeFromSight) == 1) {
                            colorDetectionDone = 1;
                        } else {
                            error = 1;
                        }

                    }
                }
            }
            // Avoid bouncing
            int t; for(t=0; t<50000; t++) {}
        }

        // Switch 2 pressed, mixxer
        if(GPIO_INPUT_PIN_LOW == MAP_GPIO_getInputPinValue(SWITCH2_PORT, SWITCH2_PIN)) {
            if (error != 1) {
                // Processing LED indication
                MAP_GPIO_setOutputLowOnPin(LED1_RED_PORT, LED1_RED_PIN);
                MAP_GPIO_setOutputHighOnPin(LED2_RED_PORT, LED2_RED_PIN);
                MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
                MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);

                if (configDone == 1) {

                    // Do a 10 moves mix
                    mixReal(10);

                } else {
                    error = 1;
                }
            }
        }
        // Avoid bouncing
        int t; for(t=0; t<50000; t++) {}
    }
}

