#include "MP_TMP007.h"



MP_TMP007::MP_TMP007()
{
	Serial.begin(9600);
	if (!tmp007.begin()) {
		Serial.println("Could not find a valid TMP007 sensor, check wiring!");
		while (1);
	}

}

int MP_TMP007::temp(char opt[], float treshold, uint8_t unit) const
{

	if (!strcmp(opt, ">="))
	{
		if (tmp007.readDieTempC() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (tmp007.readDieTempC()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (tmp007.readDieTempC() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (tmp007.readDieTempC() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (tmp007.readDieTempC() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (tmp007.readDieTempC() != treshold)
			return 1;
		else
			return 0;
	}


}


