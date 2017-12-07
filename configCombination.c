#include "steppers/steppersControl.h"
#include "string.h"
#include <stdio.h>

// ----------- GLOBAL COMBINATION VARIABLES INITIAL VALUE -----------
char combination[300][2] = {};
int index = 0;
int mixingMode = 0;
int detectionMode = 0;

// ----------- COMBINATION FUNCTIONS -----------
/*
     As the function of each motor change with time,
     we must save the motor Id and the direction of each combination instead.
 */
void addToCombination(int motorId, int dir) {
    // Save combination only if the mixing mode is disabled.
    if (mixingMode == 0) {
        combination[index][0] = motorId;
        combination[index][1] = dir;
        index ++;
    }
}

void readCombination(int cube[9][12]) {
    int k = 0;
    for (k=0; k<=index; k++) {
        if ((combination[k][0] == 1) ||
            (combination[k][0] == 2) ||
            (combination[k][0] == 3) ||
            (combination[k][0] == 4) ||
            (combination[k][0] == 5) ||
            (combination[k][0] == 6)) {
            rotate90Dir(motorById(combination[k][0]), combination[k][1]);
            // Wait some time
            int t = 0;
            for (t=0; t<5000; t++) {}
        }

        if (combination[k][0] == 11) {
            printf("--- End stage 1A ---\n");
        }
        if (combination[k][0] == 12) {
            printf("--- End stage 1B ---\n");
        }
        if (combination[k][0] == 20) {
            printf("--- End stage 2 ---\n");
        }
        if (combination[k][0] == 31) {
            printf("--- End stage 3A ---\n");
        }
        if (combination[k][0] == 32) {
            printf("--- End stage 3B ---\n");
        }
        if (combination[k][0] == 40) {
            printf("--- End stage 4 ---\n");
        }
        if (combination[k][0] == 50) {
            printf("--- End stage 5 ---\n");
        }
    }
}

void resetCombination() {
    memset(combination, 0, sizeof(combination[0][0]) * 300 * 2);
    index = 0;
}

// --------- DEBUGGING ONLY ---------

void humanReadCombination() {
    // Current carterState
    struct carterStateStruct cState = {1, 2, 3, 4, 5, 6};
    // 9 => Y
    // 11 => end 1a
    // 12 => end 1b
    // 20 => end 2
    // 31 => end 3a
    // 32 => end 3b
    // 40 => end 4
    // 50 => end 5

    printf("\n----- TRANSFORMATIONS TO SOLVE THE CUBE -----\n");
    int k, k1a, k1b, k2, k3a, k3b, k4, counter;
    counter = 0;

    // Count nb of real transformations
    for (k=0; k<index; k++) {
        if (combination[k][0] >= 1 && combination[k][0] <= 6 || combination[k][0] == 9) {
            counter ++;
        }
    }


    for (k=0; k<index; k++) {
        if (combination[k][0] == 11) {
            k1a = k;
            printf("\n--End stage 1a, total: %u / %f%% --\n", k, (100.0 * (float) k)/((float) counter));
        } else if (combination[k][0] == 12) {
            k1b = k;
            printf("\n--End stage 1b, total: %u / %f%% --\n", k-k1a-1, (100.0 * (float) (k-k1a-1))/((float) counter));
        } else if (combination[k][0] == 20) {
            k2 = k;
            printf("\n--End stage 2, total: %u / %f%% --\n", k-k1b-1, (100.0 * (float) (k-k1b-1))/((float) counter));
        } else if (combination[k][0] == 31) {
            k3a = k;
            printf("\n--End stage 3a, total: %u / %f%% --\n", k-k2-1, (100.0 * (float) (k-k2-1))/((float) counter));
        } else if (combination[k][0] == 32) {
            k3b = k;
            printf("\n--End stage 3b, total: %u / %f%% --\n", k-k3a-1, (100.0 * (float) (k-k3a-1))/((float) counter));
        } else if (combination[k][0] == 40) {
            k4 = k;
            printf("\n--End stage 4, total: %u / %f%% --\n", k-k3b-1, (100.0 * (float) (k-k3b-1))/((float) counter));
        } else if (combination[k][0] == 50) {
            printf("\n--End stage 5, total: %u / %f%% --\n", k-k4-1, (100.0 * (float) (k-k4-1))/((float) counter));
        } else if (combination[k][0] == 9) {
            printf("Y");
        } else {
            if (combination[k][1] == 0) {
                printf("%c", functionByIdAndState(combination[k][0], cState));
            } else {
                printf("%c'", functionByIdAndState(combination[k][0], cState));
            }
        }
    }

    printf("\n");
    printf("Total transformations: %u\n", counter);
}
