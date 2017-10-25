#include "MCP4725.h"

bool MCP4725::begin(){
    Wire.begin();
    Wire.beginTransmission(address);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

bool MCP4725::setOutputVoltage(float voltage, bool eeprom){
    float voltsPerStep = inputVoltage/4096;
    
    int setPoint = voltage/voltsPerStep;
    
    int msb = setPoint/256;
    
    int lsb = setPoint - (msb*256);
    
    Wire.beginTransmission(address);
    if(eeprom){
        Wire.write(writeDacEEPROMReg);
    }else{
        Wire.write(writeDacReg);
    }
    Wire.write(msb);
    Wire.write(lsb);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

bool MCP4725::setOutputRaw(int point, bool eeprom){
    
    int msb = point/256;
    int lsb = point - (msb*256);
    Serial.printf("Setting output to MSB: %i, LSB: %i \n", msb, lsb);
    
    Wire.beginTransmission(address);
    Wire.write(writeDacReg);
    Wire.write(msb);
    Wire.write(lsb);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

void MCP4725::setInputVoltage(float voltage){
    inputVoltage = voltage;
}
