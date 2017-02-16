#include "MP_BME280.h"



MP_BME280::MP_BME280() 
{
	Serial.begin(9600);
	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}

}

int MP_BME280::humidity(char opt[], float treshold, unit8_t unit) const
{

	if (!strcmp(opt, ">="))
	{
		if (bme.readHumidity() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readHumidity()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readHumidity() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readHumidity() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readHumidity() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readHumidity() != treshold)
			return 1;
		else
			return 0;
	}


}
