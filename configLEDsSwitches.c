#include "configLEDsSwitches.h"
#include "driverlib.h"

void configLEDsGPIO() {
    // Led 1
    MAP_GPIO_setAsOutputPin(LED1_RED_PORT, LED1_RED_PIN);
    MAP_GPIO_setOutputLowOnPin(LED1_RED_PORT, LED1_RED_PIN);
    // Led 2 Red
    MAP_GPIO_setAsOutputPin(LED2_RED_PORT, LED2_RED_PIN);
    MAP_GPIO_setOutputLowOnPin(LED2_RED_PORT, LED2_RED_PIN);
    // Led 2 Green
    MAP_GPIO_setAsOutputPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
    MAP_GPIO_setOutputLowOnPin(LED2_GREEN_PORT, LED2_GREEN_PIN);
    // Led 2 Blue
    MAP_GPIO_setAsOutputPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
    MAP_GPIO_setOutputLowOnPin(LED2_BLUE_PORT, LED2_BLUE_PIN);
}

void configSwitchesGPIO() {
    // Switch 1
    MAP_GPIO_setAsInputPinWithPullUpResistor(SWITCH1_PORT, SWITCH1_PIN);
    // Switch 2
    MAP_GPIO_setAsInputPinWithPullUpResistor(SWITCH2_PORT, SWITCH2_PIN);
}
