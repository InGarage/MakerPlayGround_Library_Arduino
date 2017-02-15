#include "MP_Si7021.h"
#include <iostream>
#include <string>


MP_Si7021::MP_Si7021()
{
	sensor = Adafruit_Si7021();
	Serial.begin(115200);
	if (!sensor.begin()) {
		Serial.println("Could not find a valid Si7021 sensor, check wiring!");
		while (1);
	}

}

int humidity(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (sensor.readHumidity() >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (sensor.readHumidity()> std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (sensor.readHumidity() == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (sensor.readHumidity() < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (sensor.readHumidity() <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (sensor.readHumidity() != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}

int temp(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (sensor.readTemperature() >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (sensor.readTemperature()> std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (sensor.readTemperature() == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (sensor.readTemperature() < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (sensor.readTemperature() <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (sensor.readTemperature() != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}


