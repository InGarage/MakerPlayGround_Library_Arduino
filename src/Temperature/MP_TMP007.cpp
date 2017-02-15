#include "MP_TMP007.h"
#include <iostream>
#include <string>


MP_TMP007::MP_TMP007()
{
	Serial.begin(9600);
	if (!tmp007.begin()) {
		Serial.println("Could not find a valid TMP007 sensor, check wiring!");
		while (1);
	}

}

int temp(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (tmp007.readDieTempC() >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (tmp007.readDieTempC()> std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (tmp007.readDieTempC() == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (tmp007.readDieTempC() < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (tmp007.readDieTempC() <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (tmp007.readDieTempC() != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}


