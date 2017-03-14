#include "MP_Si7021.h"



void MP_Si7021::init() 
{
	sensor = Adafruit_Si7021();

	if (!sensor.begin()) {
		Serial.println("Could not find a valid Si7021 sensor, check wiring!");
		while (1);
	}

}

int MP_Si7021::checkTemp(char opt[], float treshold, uint8_t unit) 
{

	if (!strcmp(opt, ">="))
	{
		if (sensor.readTemperature() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (sensor.readTemperature()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (sensor.readTemperature() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (sensor.readTemperature() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (sensor.readTemperature() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (sensor.readTemperature() != treshold)
			return 1;
		else
			return 0;
	}



}


int MP_Si7021::humidity(char opt[], float treshold, uint8_t unit) 
{

	if (!strcmp(opt, ">="))
	{
		if (sensor.readHumidity() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (sensor.readHumidity()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (sensor.readHumidity() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (sensor.readHumidity() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (sensor.readHumidity() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (sensor.readHumidity() != treshold)
			return 1;
		else
			return 0;
	}


}
