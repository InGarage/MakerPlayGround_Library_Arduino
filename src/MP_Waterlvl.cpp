#include "MP_Waterlvl.h"


MP_Waterlvl::MP_Waterlvl(uint8_t pin) 
	:pin(pin)
{

}

void MP_Waterlvl::init() 

{
	pinMode(pin, INPUT_PULLUP);
}


int MP_Waterlvl::isWet() 
{
	int returnVal = 0;
	if (digitalRead(pin) == LOW)
		returnVal++;
	return returnVal;
}
