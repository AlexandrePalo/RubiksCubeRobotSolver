#include "driverlib.h"

#define TIMEOUT 10000
#define MEAS_DELAY 150000

/* Sensor wiring
 * GND <--> GND
 * VIN <--> 5V OR V3.3 <--> 3.3V
 * SCL <--> P6.5
 * SDA <--> P6.4
 */

#define I2C_CMD_BIT 0x80 // Cmd bit
#define TCS34725_ADDRESS 0x29 // I2C default address of the sensor
#define TCS34725_RDATAL_REG 0x16 // Red data register, default 0x00
#define TCS34725_RDATAH_REG 0x17
#define TCS34725_GDATAL_REG 0x18 // Green data register, default 0x00
#define TCS34725_GDATAH_REG 0x19
#define TCS34725_BDATAL_REG 0x1A // Blue data register, default 0x00
#define TCS34725_BDATAH_REG 0x1B
#define TCS34725_CDATAL_REG 0x14 // Clear data register, default 0x00
#define TCS34725_CDATAH_REG 0x15
#define TCS34725_ENABLE_REG 0x00 // Enable register, default 0x00
#define TCS34725_ATIME_REG 0x01 // RGBC Time register, default 0xFF
#define TCS34725_CONTROL_REG 0x0F // Control register, default 0x00
#define TCS34725_ID_REG 0x12 // ID register, stores the ID that should be 68 decimal

void colorSensorConfig();
uint16_t readRedRaw();
uint16_t readGreenRaw();
uint16_t readBlueRaw();
uint16_t readClearRaw();
void printRawColor();
int getColorInt();
int getColorIntConsolidated();
