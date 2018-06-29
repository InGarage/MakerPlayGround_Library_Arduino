#include "MP_Soil.h"

MP_Soil::MP_Soil(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_Soil::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

double MP_Soil::getHumidity() 
{
    MP_Log::i(tag,(analogRead(pin)/1023.0)*100.0);
	return (analogRead(pin)/1023.0)*100.0;
}


