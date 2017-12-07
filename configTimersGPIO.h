#include "driverlib.h"

/*
    ----------- TIMERS CONFIG -----------
    * PWM timer for steppers
        200Hz=(15000, 7500), 300Hz=(10000, 5000), 400Hz=(7500, 3750)

    * PWM timer for servo
        period: 20 ms, (20*10^-3)/(1/3MHz) = 60000
        duty 90° CW: 1400 (empiric)
        duty 90° CCW: 7000 (empiric)
 */
#define STEPPERS_CONTROL_PWM_PERIOD 7500
#define STEPPERS_CONTROL_PWM_DUTY 3750
#define SERVO_CONTROL_PWM_PERIOD 60000
#define SERVO_CONTROL_PWM_DUTY_THIRD 3800
#define SERVO_CONTROL_PWM_DUTY_TWOTHIRD 4800
#define SERVO_CONTROL_PWM_DUTY_90CW 1400 // 1400
#define SERVO_CONTROL_PWM_DUTY_90CCW 6100 // 7000
#define SERVO_CONTRO_PWM_DUTY_REG TA2CCR1 // It'll change in the code, so I define it here.

/*
    ----------- STEPPERS CONTROL CONFIG -----------
    Stepper     1   2   3   4   5   6
    Func        F   B   R   L   U   D
    ENABLE PIN  3.2 6.1 3.3 4.0 4.1 4.2
    DIR PIN     all 4.3
    PWM: see configTimersGPIO.h
 */
#define STPR_1_ENABLE_PORT GPIO_PORT_P3
#define STPR_1_ENABLE_PIN GPIO_PIN2
#define STPR_2_ENABLE_PORT GPIO_PORT_P6
#define STPR_2_ENABLE_PIN GPIO_PIN1
#define STPR_3_ENABLE_PORT GPIO_PORT_P3
#define STPR_3_ENABLE_PIN GPIO_PIN3
#define STPR_4_ENABLE_PORT GPIO_PORT_P4
#define STPR_4_ENABLE_PIN GPIO_PIN0
#define STPR_5_ENABLE_PORT GPIO_PORT_P4
#define STPR_5_ENABLE_PIN GPIO_PIN1
#define STPR_6_ENABLE_PORT GPIO_PORT_P4
#define STPR_6_ENABLE_PIN GPIO_PIN2
#define STPR_DIR_PORT GPIO_PORT_P4
#define STPR_DIR_PIN GPIO_PIN3

void timersConfig();
void steppersPinsConfig();
