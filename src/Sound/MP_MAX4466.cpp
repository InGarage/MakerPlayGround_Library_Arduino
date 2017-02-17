#include "MP_MAX4466.h"



MP_MAX4466::MP_MAX4466(uint8_t pin)
{
	pinMode(pin, INPUT);

}

int MP_MAX4466::vol(char opt[], float treshold) const
{

	if (!strcmp(opt, ">="))
	{
		if (analogRead(pin)/1024 >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (analogRead(pin)/1024> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (analogRead(pin)/1024 == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (analogRead(pin)/1024 < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (analogRead(pin)/1024 <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (analogRead(pin)/1024 != treshold)
			return 1;
		else
			return 0;
	}


}


