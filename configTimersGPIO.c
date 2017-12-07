#include "configTimersGPIO.h"
#include "driverlib.h"


void timersConfig() {
    /*
        ----------- TIMERS CONFIG -----------
        The project needs 2 timers:
            - for ENABLEpers control PWM
            - for servo motor control PWM
            - for I2C clock, 1 clock

        DCO clock is default 3MHz
        SMCLK is tied to DCO
        TimerA0 & TimerA2
     */
    MAP_CS_setDCOFrequency(3E+6); // DCO clock frequency 3MHz
    MAP_CS_initClockSignal(CS_SMCLK, CS_DCOCLK_SELECT, CS_CLOCK_DIVIDER_1); // Tie SMCLK to DCO

    // TimerA0.3: PWM steppers control
    // Pin 2.6 primary module function
    P2SEL0 |= 0x40;
    P2SEL1 &= ~0x40;
    P2DIR |= 0x40;
    TA0CCR0 = STEPPERS_CONTROL_PWM_PERIOD;
    TA0CCR3 = 0;
    TA0CCTL3 = OUTMOD_7; // output mode 7,  macro which is equal to 0x00e0, defined in msp432p401r.h
    TA0CCTL0 |= CCIE; // Enable interrupt on each period
    TA0CTL = TASSEL__SMCLK | MC__UP | TACLR;   // Tie Timer A to SMCLK, use Up mode, and clear TA0R
    MAP_Interrupt_enableInterrupt(INT_TA0_0);

    // TimerA2.1: PWM servo motor control
    // Pin 5.6 primary module function
    P5SEL0 |= 0x40;
    P5SEL1 &= ~0x40;
    P5DIR |= 0x40;
    TA2CCR0 = SERVO_CONTROL_PWM_PERIOD;
    SERVO_CONTRO_PWM_DUTY_REG = SERVO_CONTROL_PWM_DUTY_90CW;
    TA2CCTL1 = OUTMOD_7; // output mode 7,  macro which is equal to 0x00e0, defined in msp432p401r.h
    TA2CTL = TASSEL__SMCLK | MC__UP | TACLR;   // Tie Timer A to SMCLK, use Up mode, and clear TA0R
}

void steppersPinsConfig() {
    // ENABLE pins, default high = enabled
    MAP_GPIO_setAsOutputPin(STPR_1_ENABLE_PORT, STPR_1_ENABLE_PIN);
    MAP_GPIO_setAsOutputPin(STPR_2_ENABLE_PORT, STPR_2_ENABLE_PIN);
    MAP_GPIO_setAsOutputPin(STPR_3_ENABLE_PORT, STPR_3_ENABLE_PIN);
    MAP_GPIO_setAsOutputPin(STPR_4_ENABLE_PORT, STPR_4_ENABLE_PIN);
    MAP_GPIO_setAsOutputPin(STPR_5_ENABLE_PORT, STPR_5_ENABLE_PIN);
    MAP_GPIO_setAsOutputPin(STPR_6_ENABLE_PORT, STPR_6_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_1_ENABLE_PORT, STPR_1_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_2_ENABLE_PORT, STPR_2_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_3_ENABLE_PORT, STPR_3_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_4_ENABLE_PORT, STPR_4_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_5_ENABLE_PORT, STPR_5_ENABLE_PIN);
    MAP_GPIO_setOutputHighOnPin(STPR_6_ENABLE_PORT, STPR_6_ENABLE_PIN);
    // DIR pin, default low (arbitrary)
    MAP_GPIO_setAsOutputPin(STPR_DIR_PORT, STPR_DIR_PIN);
    MAP_GPIO_setOutputLowOnPin(STPR_DIR_PORT, STPR_DIR_PIN);
}
