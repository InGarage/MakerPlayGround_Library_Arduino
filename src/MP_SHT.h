#ifndef MP_SHT_H
#define MP_SHT_H

#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"

class MP_SHT
{
public:
    void init();
    double getTemperature();
    double getHumidity();

private:
    SHTSensor sht;
};

#endif