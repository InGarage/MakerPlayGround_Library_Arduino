#include "MP_OneAnalogReadToPercent.h"

MP_OneAnalogReadToPercent::MP_OneAnalogReadToPercent(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_OneAnalogReadToPercent::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}


double MP_OneAnalogReadToPercent::getPercent()
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100);
	return (analogRead(pin)/1023.0)*100;
}


