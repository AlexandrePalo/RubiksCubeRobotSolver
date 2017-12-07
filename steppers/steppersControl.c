#include "driverlib.h"
#include "configState.h"
#include "configTimersGPIO.h"

void rotateMotor(struct motorStateStruct motor, int dir, int steps) {
    // TODO: increment the steps in PWM interrupt

    // Set the direction
    if (dir == 0) {
        MAP_GPIO_setOutputLowOnPin(STPR_DIR_PORT, STPR_DIR_PIN);
    } else {
        MAP_GPIO_setOutputHighOnPin(STPR_DIR_PORT, STPR_DIR_PIN);
    }

    // Enable the motor & wait some time
    MAP_GPIO_setOutputLowOnPin(motor.enable_port, motor.enable_pin);
    int t = 0; for(t=0; t<70000; t++) {}

    stepCounter = 0;
    // Wait until "steps" steps are done by the motor
    // TODO: for the moment, add a timer on the same period ?
    TA0CCR3 = STEPPERS_CONTROL_PWM_DUTY;
    while (stepCounter < steps) {}
    TA0CCR3 = 0;

    // Disable the motor and reset counter
    MAP_GPIO_setOutputHighOnPin(motor.enable_port, motor.enable_pin);
    stepCounter = 0;
}


void TA0_0_IRQHandler() {
    stepCounter ++;
    TA0CCTL0 &= ~CCIFG;
}

void rotate90CW(struct motorStateStruct motor) {
    // 90° = 200/4 steps
    // CW = (dir=0)
    rotateMotor(motor, 0, 100);
}

void rotate90CCW(struct motorStateStruct motor) {
    // 90° = 200/4 steps
    // CCW = (dir=1)
    rotateMotor(motor, 1, 100);
}

// --------- KNOWING THE MOTOR ID (for solving) ----------------
void rotate90Dir(struct motorStateStruct motor, int dir) {
    if (dir == 0) {
        rotate90CW(motor);
    } else {
        rotate90CCW(motor);
    }
}

// --------- KNOWING THE FUNCTION (for cube detection) ---------
void realF() {
    rotate90CW(motorByFunction('F'));
}
void realFc() {
    rotate90CCW(motorByFunction('F'));
}
void realR() {
    rotate90CW(motorByFunction('R'));
}
void realRc() {
    rotate90CCW(motorByFunction('R'));
}
void realL() {
    rotate90CW(motorByFunction('L'));
}
void realLc() {
    rotate90CCW(motorByFunction('L'));
}
void realB() {
    rotate90CW(motorByFunction('B'));
}
void realBc() {
    rotate90CCW(motorByFunction('B'));
}
void realU() {
    rotate90CW(motorByFunction('U'));
}
void realUc() {
    rotate90CCW(motorByFunction('U'));
}
void realD() {
    rotate90CW(motorByFunction('D'));
}
void realDc() {
    rotate90CCW(motorByFunction('D'));
}
