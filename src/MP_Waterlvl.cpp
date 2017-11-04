#include "MP_Waterlvl.h"

MP_Waterlvl::MP_Waterlvl(uint8_t pin) 
	:pin(pin)
{
}

void MP_Waterlvl::init()
{
}

bool MP_Waterlvl::isWet()
{
	return analogRead(pin) > 512;
}

bool MP_Waterlvl::isDry()
{
	return analogRead(pin) < 512;
}