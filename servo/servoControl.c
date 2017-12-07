#include "configTimersGPIO.h"
#define DELAY_SERVO 100000

// ----------- SERVO MVT FUNCTIONS -----------

// Extremities
void goToExtremBack() {
    SERVO_CONTRO_PWM_DUTY_REG = SERVO_CONTROL_PWM_DUTY_90CW;
    int i; for(i=0; i<DELAY_SERVO; i++) {}
}

void goToLeftOfLine() {
    SERVO_CONTRO_PWM_DUTY_REG = SERVO_CONTROL_PWM_DUTY_90CCW;
    int i; for(i=0; i<DELAY_SERVO; i++) {}
}

void goToMiddleOfLine() {
    SERVO_CONTRO_PWM_DUTY_REG = SERVO_CONTROL_PWM_DUTY_TWOTHIRD;
    int i; for(i=0; i<DELAY_SERVO; i++) {}
}

void goToRightOfLine() {
    SERVO_CONTRO_PWM_DUTY_REG = SERVO_CONTROL_PWM_DUTY_THIRD;
    int i; for(i=0; i<DELAY_SERVO; i++) {}
}
