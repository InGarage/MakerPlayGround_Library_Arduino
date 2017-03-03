#include "MP_BME280.h"



void MP_BME280::init() const 
{
	
	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}

}

int MP_BME280::pressure(char opt[], float treshold, uint8_t unit) const
{
	
	if (!strcmp(opt, ">="))
	{
		if ((bme.readPressure() / 100.0F) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if ((bme.readPressure() / 100.0F) > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if ((bme.readPressure() / 100.0F) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if ((bme.readPressure() / 100.0F) < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if ((bme.readPressure() / 100.0F) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if ((bme.readPressure() / 100.0F) != treshold)
			return 1;
		else
			return 0;
	}	
	
	
}

int MP_BME280::attitude(char opt[], float treshold, uint8_t unit) const
{

	if (!strcmp(opt, ">="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) != treshold)
			return 1;
		else
			return 0;
	}


}

int MP_BME280::humidity(char opt[], float treshold, uint8_t unit) const
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

int MP_BME280::checkTemp(char opt[], float treshold, uint8_t unit) const
{
	if (!strcmp(opt, ">="))
	{
		if (bme.readTemperature() >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readTemperature()> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readTemperature() == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readTemperature() < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readTemperature() <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readTemperature() != treshold)
			return 1;
		else
			return 0;
	}
}



