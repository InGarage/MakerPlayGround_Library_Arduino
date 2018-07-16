#include "MP_SHT.h"

MP_SHT::MP_SHT()
{
}

void MP_SHT::init()
{
    Wire.begin();
    sht.init();
}

double MP_SHT::getTemperature()
{
    sht.readSample();
    return sht.getTemperature();
}

double MP_SHT::getHumidity()
{
    sht.readSample();
    return sht.getHumidity();
}