#include "MP_PIR.h"


MP_PIR::MP_PIR(uint8_t pin)
  : pin(pin)
{
  
}

void MP_PIR::init() 
{
	pinMode(this->pin,INPUT);
}


double MP_PIR::getValue() 
{
  return  digitalRead(pin)*1.0; 
}

