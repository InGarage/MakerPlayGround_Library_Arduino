#include "MP_GROVE_PIR.h"


MP_GROVE_PIR::MP_GROVE_PIR(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GROVE_PIR::init() 
{
	pinMode(this->pin,INPUT);
}

int MP_GROVE_PIR::isDetected() 
{
  return  digitalRead(pin) == HIGH;
}

int MP_GROVE_PIR::isNotDetected()
{
  return  digitalRead(pin) == LOW;
}