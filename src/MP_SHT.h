#ifndef MP_SHT_H
#define MP_SHT_H

#include <Arduino.h>
#include <Wire.h>
#include "SHTSensor.h"
#include "MP_Log.h"

class MP_SHT
{
public:
    MP_SHT(const String &tag);
    void init();
    double getTemperature();
    double getHumidity();

private:
    SHTSensor sht;
    const String tag;
};

#endif