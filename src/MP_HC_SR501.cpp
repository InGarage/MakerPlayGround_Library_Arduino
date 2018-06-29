#include "MP_HC_SR501.h"


MP_HC_SR501::MP_HC_SR501(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_HC_SR501::init() 
{
	pinMode(this->pin,INPUT);
	MP_Log::i(tag,"Ready");
}

int MP_HC_SR501::isDetected() 
{
  MP_Log::i(tag,"Detected");
  return  digitalRead(pin) == HIGH;

}

int MP_HC_SR501::isNotDetected()
{
  MP_Log::i(tag,"Not detected");
  return  digitalRead(pin) == LOW;
}