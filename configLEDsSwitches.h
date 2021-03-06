// -------- LEDs GPIO --------
#define LED1_RED_PORT GPIO_PORT_P1
#define LED1_RED_PIN GPIO_PIN0
#define LED2_RED_PORT GPIO_PORT_P2
#define LED2_RED_PIN GPIO_PIN0
#define LED2_GREEN_PORT GPIO_PORT_P2
#define LED2_GREEN_PIN GPIO_PIN1
#define LED2_BLUE_PORT GPIO_PORT_P2
#define LED2_BLUE_PIN GPIO_PIN2

// -------- SWITCHES GPIO --------
#define SWITCH1_PORT GPIO_PORT_P1
#define SWITCH1_PIN GPIO_PIN1
#define SWITCH2_PORT GPIO_PORT_P1
#define SWITCH2_PIN GPIO_PIN4

// -------- FUNCTIONS --------
void configLEDsGPIO();
void configSwitchesGPIO();
