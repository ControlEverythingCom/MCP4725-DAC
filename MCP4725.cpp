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
    float voltsPerStep = inputVoltage/4095;
    
    int setPoint = voltage/voltsPerStep;
    Serial.printf("Set Point: %i\n", setPoint);
    
    Wire.beginTransmission(address);
    if(eeprom){
        Wire.write(writeDacEEPROMReg);
    }else{
        Wire.write(writeDacReg);
    }
    Wire.write(setPoint >> 4);
    Wire.write((setPoint & 15)<<4);
    byte status = Wire.endTransmission();
    if(status == 0){
        return true;
    }else{
        return false;
    }
}

bool MCP4725::setOutputRaw(int point, bool eeprom){
    
    Wire.beginTransmission(address);
    Wire.write(writeDacReg);
    Wire.write(point >> 4);
    Wire.write((point&15)<<4);
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
