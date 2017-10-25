#include "spark_wiring_i2c.h"
#include "spark_wiring_constants.h"
#include "spark_wiring_usbserial.h"
class MCP4725{
public:

bool begin(bool addrJumper);

bool setOutputVoltage(float voltage, bool eeprom);

bool setOutputRaw(int point, bool eeprom);

void setInputVoltage(float voltage);

private:

int address = 0x60;

int writeDacReg = 0x40;

int writeDacEEPROMReg = 0x60;

float inputVoltage = 0;

};
