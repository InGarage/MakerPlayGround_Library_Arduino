#include "MP_Si7021.h"



MP_Si7021::MP_Si7021()
{
	sensor = Adafruit_Si7021();
	Serial.begin(115200);
	if (!sensor.begin()) {
		Serial.println("Could not find a valid Si7021 sensor, check wiring!");
		while (1);
	}

}

int MP_Si7021::temp(char opt[], float treshold, uint8_t unit) const
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
