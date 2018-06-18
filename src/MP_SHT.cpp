#include "MP_SHT.h"

MP_SHT::MP_SHT(const String &tag)
	: tag(tag)
{
}

void MP_SHT::init()
{
    Wire.begin();
    sht.init();
    MP_Log::i(tag,"Ready");
}

double MP_SHT::getTemperature()
{
    sht.readSample();
    MP_Log::i(tag,sht.getTemperature());
    return sht.getTemperature();
}

double MP_SHT::getHumidity()
{
    sht.readSample();
    MP_Log::i(tag,sht.getHumidity());
    return sht.getHumidity();
}