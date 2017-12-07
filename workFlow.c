#include "sensor/colorUtils.h"
#include "sensor/colorSensor.h"
#include "servo/servoControl.h"
#include "steppers/steppersControl.h"
#include "solver/solver.h"
#include "configCombination.h"
#include "configTimersGPIO.h"
#include "configLEDsSwitches.h"
#include "solver/validator.h"
#include "solver/reducer.h"
#include <stdio.h>

    /*
             0    1   2  3   4   5   6    7  8    9  10   11

       0    {00, 00, 00, 01, 02, 03, 00, 00, 00, 00, 00, 00},
       1    {00, 00, 00, 04, 05, 06, 00, 00, 00, 00, 00, 00},
       2    {00, 00, 00, 07, 08, 09, 00, 00, 00, 00, 00, 00},
       3    {10, 11, 12, 19, 20, 21, 28, 29, 30, 37, 38, 39},
       4    {13, 14, 15, 22, 23, 24, 31, 32, 33, 40, 41, 42},
       5    {16, 17, 18, 25, 26, 27, 34, 35, 36, 43, 44, 45},
       6    {00, 00, 00, 46, 47, 48, 00, 00, 00, 00, 00, 00},
       7    {00, 00, 00, 49, 50, 51, 00, 00, 00, 00, 00, 00},
       8    {00, 00, 00, 52, 53, 54, 00, 00, 00, 00, 00, 00}
       */

//#include "configState.h"

// ----------- CONFIGURATION ------------
int fullConfig() {
    // TODO: change error state generation

    // Hold watchdog timer
    WDT_A_holdTimer();

    // Config Timers, PWM & GPIO for PWM
    timersConfig();
    steppersPinsConfig();

    // Config LEDs & switches
    configLEDsGPIO();
    configSwitchesGPIO();

    // Config Sensor
    colorSensorConfig();

    MAP_Interrupt_enableMaster();

    return 1;
}

// ----------- CUBE DETECTION -----------
int detectCube(int cube[9][12], int cubeFromSight[9][12]) {
    /*
     Move the sensor and transform the initial cube to detect the whole matrix.
     The final cubeMatrix after this function is the initial cubeMatrix,
     each real transformation is cancelled by real transformation^-1.
     */

    // ----- F -----
    // CENTER MUST BE RED
    cube[7][4] = RED;
    // Detection 1
    goToLeftOfLine();
    cube[8][3] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[8][4] = getColorIntConsolidated();
    goToRightOfLine();
    cube[8][5] = getColorIntConsolidated();
    // Detection 2
    goToExtremBack();
    realF();
    goToMiddleOfLine();
    cube[7][3] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[6][3] = getColorIntConsolidated();
    // Detection 3
    goToExtremBack();
    realF();
    goToLeftOfLine();
    cube[6][5] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[6][4] = getColorIntConsolidated();
    // Detection 4
    goToExtremBack();
    realF();
    goToMiddleOfLine();
    cube[7][5] = getColorIntConsolidated();
    goToExtremBack();
    realF();

    // ----- R -----
    // CENTER MUST BE BLUE
    cube[4][7] = BLUE;
    // Detection 1
    realU();
    realL();
    realLc();
    goToLeftOfLine();
    cube[5][8] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][8] = getColorIntConsolidated();
    goToRightOfLine();
    cube[3][8] = getColorIntConsolidated();
    goToExtremBack();
    realUc();
    // Detection 2
    realR();
    realU();
    realL();
    realLc();
    goToMiddleOfLine();
    cube[5][7] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[5][6] = getColorIntConsolidated();
    goToExtremBack();
    realUc();
    // Detection 3
    realR();
    realU();
    realL();
    realLc();
    goToLeftOfLine();
    cube[3][6] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][6] = getColorIntConsolidated();
    goToExtremBack();
    realUc();
    // Detection 4
    realR();
    realU();
    goToMiddleOfLine();
    cube[3][7] = getColorIntConsolidated();
    goToExtremBack();
    realUc();
    realR();

    // ----- L -----
    // CENTER MUST BE GREEN
    cube[4][1] = GREEN;
    // Detection 1
    realUc();
    goToLeftOfLine();
    cube[3][0] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][0] = getColorIntConsolidated();
    goToRightOfLine();
    cube[5][0] = getColorIntConsolidated();
    goToExtremBack();
    realU();
    // Detection 2
    realL();
    realUc();
    goToMiddleOfLine();
    cube[3][1] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[3][2] = getColorIntConsolidated();
    goToExtremBack();
    realU();
    // Detection 3
    realL();
    realUc();
    goToLeftOfLine();
    cube[5][2] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][2] = getColorIntConsolidated();
    goToExtremBack();
    realU();
    // Detection 4
    realL();
    realUc();
    goToMiddleOfLine();
    cube[5][1] = getColorIntConsolidated();
    goToExtremBack();
    realU();
    realL();

    // ----- U -----
    // CENTER MUST BE WHITE
    cube[4][10] = WHITE;
    // Detection 1
    realL();
    realF();
    goToLeftOfLine();
    cube[5][11] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][11] = getColorIntConsolidated();
    goToRightOfLine();
    cube[3][11] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    // Detection 2
    realU();
    realL();
    realF();
    goToMiddleOfLine();
    cube[5][10] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[5][9] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    // Detection 3
    realU();
    realL();
    realF();
    goToLeftOfLine();
    cube[3][9] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][9] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    // Detection 4
    realU();
    realL();
    realF();
    goToMiddleOfLine();
    cube[3][10] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    realU();

    // ----- D -----
    // CENTER MUST BE YELLOW
    cube[4][4] = YELLOW;
    // Detection 1
    realLc();
    realF();
    goToLeftOfLine();
    cube[3][3] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][3] = getColorIntConsolidated();
    goToRightOfLine();
    cube[5][3] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realL();
    // Detection 2
    realD();
    realLc();
    realF();
    goToMiddleOfLine();
    cube[3][4] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[3][5] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realL();
    // Detection 3
    realD();
    realLc();
    realF();
    goToLeftOfLine();
    cube[5][5] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[4][5] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realL();
    // Detection 4
    realD();
    realLc();
    realF();
    goToMiddleOfLine();
    cube[5][4] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realL();
    realD();

    // ----- B -----
    // CENTER MUST BE ORANGE
    cube[1][4] = ORANGE;
    // Detection 1
    realL();
    realL();
    realF();
    goToLeftOfLine();
    cube[0][3] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[1][3] = getColorIntConsolidated();
    goToRightOfLine();
    cube[2][3] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    realLc();
    // Detection 2
    realB();
    realL();
    realL();
    realF();
    goToMiddleOfLine();
    cube[0][4] = getColorIntConsolidated();
    goToLeftOfLine();
    cube[0][5] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    realLc();
    // Detection 3
    realB();
    realL();
    realL();
    realF();
    goToLeftOfLine();
    cube[2][5] = getColorIntConsolidated();
    goToMiddleOfLine();
    cube[1][5] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    realLc();
    // Detection 4
    realB();
    realL();
    realL();
    realF();
    goToMiddleOfLine();
    cube[2][4] = getColorIntConsolidated();
    goToExtremBack();
    realFc();
    realLc();
    realLc();
    realB();


    // Go back to the initial position
    goToExtremBack();

    printf("Cube detected:\n");
    printfCube(cube);

    printf("Cube from sight:\n");
    printfCube(cubeFromSight);

    // Compare
    printf("\n----- DETECTED VS REAL CUBE -----\n");
    int m,n;
    int errorCount = 0;

    for (m=0; m<9; m++) {
        for (n=0; n<12; n++) {
            if (cube[m][n] != cubeFromSight[m][n]) {
                printf("Error: %u was wrongly considered as %u\n", cubeFromSight[m][n], cube[m][n]);
                errorCount ++;
            }
        }
    }
    printf("\nResults: %u error(s) (%f %%)\n", errorCount, ((float) errorCount) * 100.0 / 54.0 );


    return 1;
}

// ----------- CUBE SOLVING -----------
int solveCube(int cube[9][12]) {
    /*
       Solve the cube matrix using the beginner algorithm
       Store combinations in the array combination, by tuples (n° motor, dir)
     */

    // Check solvability
    if (validatorCube(cube) == 1) {
        // Solve cube
        if (solver(cube) == 1) {
            humanReadCombination();
            //printf("reduce: %u", reduceCombination());
            return 1;
        } else {
            return 0;
        }
    } else {
        return 0;
    }

}

// ----------- COMBINATION EXECUTION -----------
int executeCube() {
    printf("\n----- EXECUTION -----\n");
    // Execute each combination in combinations array
    readCombination();
    return 1;
}
