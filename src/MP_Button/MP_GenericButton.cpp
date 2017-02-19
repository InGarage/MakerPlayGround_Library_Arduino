#include "MP_GenericButton.h"


MP_GenericButton::MP_GenericButton(uint8_t pin) 
	:pin(pin)
{

}

void MP_GenericButton::init(uint8_t pin) const

{
	pinMode(pin, INPUT_PULLUP);
}


int MP_GenericButton::release() const
{
	int returnVal = 0;
	if (digitalRead(pin) == LOW)
		returnVal++;
	while (digitalRead(pin) == LOW);
	return returnVal;
}


int MP_GenericButton::doubleRelease() const
{
	
	if (digitalRead(pin) == LOW)
	{
		while (digitalRead(pin) == LOW);
		while (count < 100)
		{
			count++;
			if (digitalRead(pin) == LOW)
				returnVal++;
		}
		while (digitalRead(pin) == LOW);
		return 1;
	}
	return 0;

}
