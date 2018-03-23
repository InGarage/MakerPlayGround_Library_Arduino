#include "MP_GROVE_Temperature.h"

MP_GROVE_Temperature::MP_GROVE_Temperature(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GROVE_Temperature::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_GROVE_Temperature::getTemperature() 
{
	// return -40 + (analogRead(pin)/1023.0) * (125 - (-40));
    return analogRead(pin)/1023.0 * 125 - 40;
}


