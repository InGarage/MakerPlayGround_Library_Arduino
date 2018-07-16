#ifndef MP_FLOW_SENSOR_H
#define MP_FLOW_SENSOR_H

#include <Arduino.h>
#include "PinChangeInterrupt.h"

class MP_FlowSensor
{
  public:
    MP_FlowSensor(uint8_t pin);
    MP_FlowSensor(){};

    void init();
    void update(unsigned long time);
    int isWaterFlow();
    double getFlow_Rate();
    double getTotal_Water_Amount();

  private:
    uint8_t pin;

    double calibrationFactor;

    unsigned long oldTime;
    double flowRate;
    double flowMilliLitres;
    double totalMilliLitres;
    int flowChange;

    static volatile unsigned int pulseCount;
    static void interruptHandler();
};

#endif