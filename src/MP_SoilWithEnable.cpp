#include "MP_SoilWithEnable.h"

MP_SoilWithEnable::MP_SoilWithEnable(uint8_t data, uint8_t en)
  : data(data)
  , en(en)
{
}

void MP_SoilWithEnable::init() 
{
	pinMode(data, INPUT);
    pinMode(en, OUTPUT);
}

double MP_SoilWithEnable::getHumidity() 
{
    digitalWrite(en, HIGH);
    delay(5);
	double value = (analogRead(data) / 1023.0) * 100.0;
    digitalWrite(en, LOW);
    return value;
}


