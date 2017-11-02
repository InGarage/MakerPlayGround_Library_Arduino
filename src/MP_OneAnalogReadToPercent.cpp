#include "MP_OneAnalogReadToPercent.h"

MP_OneAnalogReadToPercent::MP_OneAnalogReadToPercent(uint8_t pin)
  : pin(pin)
{
  
}

void MP_OneAnalogReadToPercent::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_OneAnalogReadToPercent::getPercent() 
{
	return (analogRead(pin)/1023.0)*100;
}


