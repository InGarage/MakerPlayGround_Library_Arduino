#include "MP_MAX4466.h"

MP_MAX4466::MP_MAX4466(uint8_t pin)
	:pin(pin)
{

}

void MP_MAX4466::init() const
{
	pinMode(pin, INPUT);

}

int MP_MAX4466::checkVol(char opt[], float treshold) const
{ 
	

	if (!strcmp(opt, ">="))
	{
		if (analogRead(pin) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (analogRead(pin)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (analogRead(pin) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (analogRead(pin) < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (analogRead(pin) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (analogRead(pin) != treshold)
			return 1;
		else
			return 0;
	}


}


