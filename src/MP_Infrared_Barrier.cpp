#include "MP_Infrared_Barrier.h"


MP_Infrared_Barrier::MP_Infrared_Barrier(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_Infrared_Barrier::init()
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

int MP_Infrared_Barrier::isDetected()
{
  MP_Log::i(tag,"Detected");
  return  digitalRead(pin) == LOW;
}

int MP_Infrared_Barrier::isNotDetected()
{
  MP_Log::i(tag,"Not detected");
  return  digitalRead(pin) == HIGH;
}