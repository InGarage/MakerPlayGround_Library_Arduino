#include "MP_GeneralLed.h"


MP_GeneralLed::MP_GeneralLed(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GeneralLed::init() 
{
	pinMode(this->pin, OUTPUT);
}


void MP_GeneralLed::on(int a) 
{
  digitalWrite(this->pin, HIGH);
}

void MP_GeneralLed::off() 
{
  digitalWrite(this->pin, LOW);
}


void MP_GeneralLed::dim(uint8_t percentage) 
{
	analogWrite(this->pin, 255 * percentage); /* Only PWM Pin */
}
