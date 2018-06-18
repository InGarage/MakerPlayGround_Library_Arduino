#include "MP_SoilWithEnable.h"

MP_SoilWithEnable::MP_SoilWithEnable(uint8_t data, uint8_t en,const String &tag)
  : data(data)
  , en(en)
  ,tag(tag)
{
}

void MP_SoilWithEnable::init() 
{
	pinMode(data, INPUT);
    pinMode(en, OUTPUT);
    MP_Log::i(tag,"Ready");
}

double MP_SoilWithEnable::getPercent()
{
    digitalWrite(en, HIGH);
    delay(5);
	double value = (analogRead(data) / 1023.0) * 100.0;
	digitalWrite(en, LOW);
	MP_Log::i(tag,value);
    return value;
}


