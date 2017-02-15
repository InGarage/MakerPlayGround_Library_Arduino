#include "MP_BME280.h"
#include <iostream>
#include <string>


MP_BME280::MP_BME280() 
{
	Serial.begin(9600);
	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}

}

int pressure(char opt[], char treshold[], char unit[]) const
{
	
	if (!strcmp(opt, ">="))
	{
		if ((bme.readPressure() / 100.0F) >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if ((bme.readPressure() / 100.0F) > std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if ((bme.readPressure() / 100.0F) == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if ((bme.readPressure() / 100.0F) < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if ((bme.readPressure() / 100.0F) <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if ((bme.readPressure() / 100.0F) != std::stoi(treshold))
			return 1;
		else
			return 0;
	}	
	
	
}

int attitude(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) > std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readAltitude(SEALEVELPRESSURE_HPA) != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}

int humidity(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (bme.readHumidity() >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readHumidity()> std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readHumidity() == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readHumidity() < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readHumidity() <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readHumidity() != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}

int temp(char opt[], char treshold[], char unit[]) const
{

	if (!strcmp(opt, ">="))
	{
		if (bme.readTemperature() >= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (bme.readTemperature()> std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (bme.readTemperature() == std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (bme.readTemperature() < std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (bme.readTemperature() <= std::stoi(treshold))
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (bme.readTemperature() != std::stoi(treshold))
			return 1;
		else
			return 0;
	}


}


