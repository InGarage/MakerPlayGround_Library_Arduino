#include "MP_TMP007.h"



void MP_TMP007::init() 
{

	
	if (!tmp007.begin()) {
		Serial.println("Could not find a valid TMP007 sensor, check wiring!");
		while (1);
	}

}


int MP_TMP007::checkTemp(char opt[], float treshold, uint8_t unit) 
{
	
	if (!strcmp(opt, ">="))
	{
		if (tmp007.readObjTempC() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (tmp007.readObjTempC()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (tmp007.readObjTempC() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (tmp007.readObjTempC() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (tmp007.readObjTempC() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (tmp007.readObjTempC() != treshold)
			return 1;
		else
			return 0;
	}


}


