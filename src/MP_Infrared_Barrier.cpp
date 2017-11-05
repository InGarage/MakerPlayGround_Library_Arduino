#include "MP_Infrared_Barrier.h"


MP_Infrared_Barrier::MP_Infrared_Barrier(uint8_t pin)
  : pin(pin)
{
  
}

void MP_Infrared_Barrier::init()
{
	pinMode(this->pin,INPUT);
}

int MP_Infrared_Barrier::isDetected()
{
  return  digitalRead(pin) == LOW;
}

int MP_Infrared_Barrier::isNotDetected()
{
  return  digitalRead(pin) == HIGH;
}