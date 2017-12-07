#include "msp.h"
#include "driverlib.h"
#include <stdbool.h>
#include <stdio.h>
#include <math.h>

#include "colorSensor.h"
#include "colorUtils.h"

// During each config writing, you need to add I2C_CMD_BIT (8th bit to 1)

/* Sensor wiring
 * GND <--> GND
 * VIN <--> 5V OR V3.3 <--> 3.3V
 * SCL <--> P6.5
 * SDA <--> P6.4
 */

// I2C Master Configuration Struct
volatile eUSCI_I2C_MasterConfig i2cConfig = {
        EUSCI_B_I2C_CLOCKSOURCE_SMCLK,          // SMCLK Clock Source
        3000000,                                // Use clock of 3MHz
        EUSCI_B_I2C_SET_DATA_RATE_100KBPS,      // Desired I2C Clock of 100khz
        0,                                      // No byte counter threshold
        EUSCI_B_I2C_NO_AUTO_STOP
};

void colorSensorConfig() {
    uint8_t state = 0;
    int t = 0;

    // Select I2C function for I2C_SCL & I2C_SDA
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, GPIO_PIN5,
                                                GPIO_PRIMARY_MODULE_FUNCTION);
    GPIO_setAsPeripheralModuleFunctionOutputPin(GPIO_PORT_P6, GPIO_PIN4,
                                                GPIO_PRIMARY_MODULE_FUNCTION);
    // Initializing I2C Master to SMCLK at 100kbs with no-autostop
    MAP_I2C_initMaster(EUSCI_B1_BASE, (const eUSCI_I2C_MasterConfig *)&i2cConfig);
    // Enable I2C Module to start operations
    MAP_I2C_enableModule(EUSCI_B1_BASE);

    // Enable + color RGDC
    state = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    MAP_I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_ENABLE_REG);
    MAP_I2C_masterSendMultiByteNext(EUSCI_B1_BASE, 0x01);
    state = MAP_I2C_masterSendMultiByteStopWithTimeout(EUSCI_B1_BASE, TIMEOUT);
    if (state) { printf("Power up done\n"); } else { printf("Power up error\n"); }
    for(t = 0; t < 5000; t++){} // Wait at least 2.4 ms according to the documentation
    state = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    MAP_I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_ENABLE_REG);
    MAP_I2C_masterSendMultiByteNext(EUSCI_B1_BASE, 0x03);
    state = MAP_I2C_masterSendMultiByteStopWithTimeout(EUSCI_B1_BASE, TIMEOUT);
    if (state) { printf("RGBC enable done\n"); } else { printf("RGBC enable error\n"); }

    // Setting integration time
    state = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    MAP_I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_ATIME_REG);
    state = MAP_I2C_masterSendMultiByteFinishWithTimeout(EUSCI_B1_BASE, 0xC0, TIMEOUT);
    if (state) { printf("Setting integration done\n"); } else { printf("Setting integration time error\n"); }

    /*
    // Setting gain
    state = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    MAP_I2C_setMode(EUSCI_B1_BASE, EUSCI_B_I2C_TRANSMIT_MODE);
    MAP_I2C_masterSendMultiByteStart(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_CONTROL_REG);
    state = MAP_I2C_masterSendMultiByteFinishWithTimeout(EUSCI_B1_BASE, 0x00, TIMEOUT);
    if (state) { printf("Setting gain done\n"); } else { printf("Setting gain error\n"); }
    */
}

uint16_t readRedRaw() {
    // Read the red color
     uint8_t rL = 0;
     uint8_t rH = 0;
     uint16_t redRaw = 0;
     int state = 0;
     int t = 0;
     MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
     state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_RDATAL_REG, TIMEOUT);
     for(t = 0; t < 1000; t++){}
     if (state) {
         rL = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

         state = 0;
         MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
         state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_RDATAH_REG, TIMEOUT);
         for(t = 0; t < 1000; t++){}
         if (state) {
             rH = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

             redRaw = ((uint16_t)rH << 8) | rL;
         } else {
             printf("Cannot send for rH\n");
         }
     } else {
         printf("Cannot send for rL\n");
     }
     return redRaw;
}

uint16_t readGreenRaw() {
    // Read the green color
    uint8_t gL = 0;
    uint8_t gH = 0;
    uint16_t greenRaw = 0;
    int state = 0;
    int t = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_GDATAL_REG, TIMEOUT);
    for(t = 0; t < 1000; t++){}
    if (state) {
        gL = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

        state = 0;
        MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
        state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_GDATAH_REG, TIMEOUT);
        for(t = 0; t < 1000; t++){}
        if (state) {
            gH = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

            greenRaw = ((uint16_t)gH << 8) | gL;
        } else {
            printf("Cannot send for gH\n");
        }
    } else {
        printf("Cannot send for gL\n");
    }
    return greenRaw;
}

uint16_t readBlueRaw() {
    // Read the blue color
    uint8_t bL = 0;
    uint8_t bH = 0;
    uint16_t blueRaw = 0;
    int state = 0;
    int t = 0;
    MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
    state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_BDATAL_REG, TIMEOUT);
    for(t = 0; t < 1000; t++){}
    if (state) {
        bL = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

        state = 0;
        MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
        state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_BDATAH_REG, TIMEOUT);
        for(t = 0; t < 1000; t++){}
        if (state) {
            bH = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

            blueRaw = ((uint16_t)bH << 8) | bL;
        } else {
            printf("Cannot send for bH\n");
        }
    } else {
        printf("Cannot send for bL\n");
    }
    return blueRaw;
}

uint16_t readClearRaw() {
    // Read the clear
     uint8_t cL = 0;
     uint8_t cH = 0;
     uint16_t clearRaw = 0;
     int state = 0;
     int t = 0;
     MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
     state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_CDATAL_REG, TIMEOUT);
     for(t = 0; t < 1000; t++){}
     if (state) {
         cL = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

         state = 0;
         MAP_I2C_setSlaveAddress(EUSCI_B1_BASE, TCS34725_ADDRESS);
         state = MAP_I2C_masterSendSingleByteWithTimeout(EUSCI_B1_BASE, I2C_CMD_BIT | TCS34725_CDATAH_REG, TIMEOUT);
         for(t = 0; t < 1000; t++){}
         if (state) {
             cH = MAP_I2C_masterReceiveSingleByte(EUSCI_B1_BASE);

             clearRaw = ((uint16_t)cH << 8) | cL;
         } else {
             printf("Cannot send for cH\n");
         }
     } else {
         printf("Cannot send for cL\n");
     }
     return clearRaw;
}

int getColorInt() {
    // Get raw data
    uint16_t redRaw = readRedRaw();
    uint16_t greenRaw = readGreenRaw();
    uint16_t blueRaw = readBlueRaw();
    float red = (float) (redRaw * 254) / (redRaw + greenRaw + blueRaw);
    float green = (float) (greenRaw * 254) / (redRaw + greenRaw + blueRaw);
    float blue = (float) (blueRaw * 254) / (redRaw + greenRaw + blueRaw);
    int colorInt = colorFromRaw(red, green, blue);
    return colorInt;
}

void printRawColor() {
    // Get raw data
    uint16_t redRaw = readRedRaw();
    uint16_t greenRaw = readGreenRaw();
    uint16_t blueRaw = readBlueRaw();
    float red = (float) (redRaw * 254) / (redRaw + greenRaw + blueRaw);
    float green = (float) (greenRaw * 254) / (redRaw + greenRaw + blueRaw);
    float blue = (float) (blueRaw * 254) / (redRaw + greenRaw + blueRaw);

    // Print
    printf("%f %f %f\n", red, green, blue);
}

int getColorIntConsolidated() {
    /*
     Compare two values of the color with a delayed.
     If the two values are the same, the color is consolidated.
     */

    // BE CAREFUL: the first value is ALWAYS wrong (due to int. time)
    getColorInt(); // reinitialize the sensor

    int colorArray[3] = {-1,-2,-3}; // 3 impossible values
    int i = 0;

    while (colorArray[0] != colorArray[1] ||
            colorArray[1] != colorArray[2] ||
            colorArray[1] != colorArray[2]) {
        int t = 0; for(t=0; t<MEAS_DELAY; t++) {}
        if (i<=2) {
            colorArray[i] = getColorInt();
        } else {
            i = 0;
            colorArray[i] = getColorInt();
        }
        //printf("i:%u, c:%u, t:%s\n", i, colorArray[i], colorTextFromColorInt(colorArray[i]));
        i++;
    }

    printf("%s\n", colorTextFromColorInt(colorArray[2]));
    return colorArray[2];
}
