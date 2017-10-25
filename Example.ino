// This #include statement was automatically added by the Particle IDE.
#include "MCP4725.h"

MCP4725 dac;

int setOutVoltage(String data);
int setOutVoltageRetain(String data);
int setOutputVoltageRaw(String data);
int setInVoltage(String data);

void setup() {
    if(dac.begin()){
        Serial.println("Init Success");
    }else{
        Serial.println("Device not ready");
    }
    Particle.function("SetOutput", setOutVoltage);
    Particle.function("SetOutputR", setOutVoltageRetain);
    Particle.function("SetInput", setInVoltage);
    Particle.function("SetOutputRa", setOutputVoltageRaw);
}

void loop() {

}

int setOutVoltage(String data){
    if(dac.setOutputVoltage(data.toFloat(), false)){
        return 1;
    }else{
        return 0;
    }
}

int setOutVoltageRetain(String data){
    if(dac.setOutputVoltage(data.toFloat(), true)){
        return 1;
    }else{
        return 0;
    }
}

int setOutputVoltageRaw(String data){
    if(dac.setOutputRaw(data.toFloat(), false)){
        return 1;
    }else{
        return 0;
    }
}

int setInVoltage(String data){
    dac.setInputVoltage(data.toFloat());
    return 1;
}
