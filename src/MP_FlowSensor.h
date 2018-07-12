#ifndef MP_FLOW_SENSOR_H
#define MP_FLOW_SENSOR_H

#include <Arduino.h>
#include "MP_Log.h"
#include "PinChangeInterrupt.h"

class MP_FlowSensor
{
  public:
    MP_FlowSensor(uint8_t pin, const String &tag);
    MP_FlowSensor(){};

    void init();
    void update();
    int isWaterFlow();
    double getFlow_Rate();
    double getTotal_Water_Amount();

  private:
    uint8_t pin;
    const String tag;

    float calibrationFactor;

    unsigned long oldTime;
    float flowRate;
    unsigned int flowMilliLitres;
    unsigned long totalMilliLitres;
    int flowChange;

    static volatile unsigned int pulseCount;
    static void interruptHandler();
};

#endif