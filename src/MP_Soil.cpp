#include "MP_Soil.h"

MP_Soil::MP_Soil(uint8_t pin)
  : pin(pin)
{
  
}

void MP_Soil::init() 
{
	pinMode(this->pin,INPUT);
}

double MP_Soil::getHumidity() 
{
	return (analogRead(pin)/1023.0)*100.0;
}


