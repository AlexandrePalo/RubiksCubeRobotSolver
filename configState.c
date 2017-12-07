#include "driverlib.h"
#include "configState.h"
#include "configTimersGPIO.h"

// ----------- GLOBAL VARIABLES INITIAL VALUE -----------
struct carterStateStruct carterState = {1, 2, 3, 4, 5, 6}; // F B R L U D
struct motorStateStruct stpr1 = {STPR_1_ENABLE_PORT, STPR_1_ENABLE_PIN, 1};
struct motorStateStruct stpr2 = {STPR_2_ENABLE_PORT, STPR_2_ENABLE_PIN, 2};
struct motorStateStruct stpr3 = {STPR_3_ENABLE_PORT, STPR_3_ENABLE_PIN, 3};
struct motorStateStruct stpr4 = {STPR_4_ENABLE_PORT, STPR_4_ENABLE_PIN, 4};
struct motorStateStruct stpr5 = {STPR_5_ENABLE_PORT, STPR_5_ENABLE_PIN, 5};
struct motorStateStruct stpr6 = {STPR_6_ENABLE_PORT, STPR_6_ENABLE_PIN, 6};
int stepCounter = 0;

// ----------- MOTOR MAPPING FUNCTIONS -----------
struct motorStateStruct motorById(int id) {
    switch (id) {
        case 1:
            return stpr1;
        case 2:
            return stpr2;
        case 3:
            return stpr3;
        case 4:
            return stpr4;
        case 5:
            return stpr5;
        case 6:
            return stpr6;
    }
}

int motorIdByFunction(char function) {
    switch (function) {
        case 'F':
            return carterState.F;
        case 'B':
            return carterState.B;
        case 'R':
            return carterState.R;
        case 'L':
            return carterState.L;
        case 'U':
            return carterState.U;
        case 'D':
            return carterState.D;
    }
}

struct motorStateStruct motorByFunction(char function) {
    return motorById(motorIdByFunction(function));
}

char functionByIdAndState(int motorId, struct carterStateStruct carterStruct) {
    if (carterStruct.F == motorId) {
        return 'F';
    } else if (carterStruct.B == motorId) {
        return 'B';
    } else if (carterStruct.R == motorId) {
        return 'R';
    } else if (carterStruct.L == motorId) {
        return 'L';
    } else if (carterStruct.U == motorId) {
        return 'U';
    } else if (carterStruct.D == motorId) {
        return 'D';
    }
}
