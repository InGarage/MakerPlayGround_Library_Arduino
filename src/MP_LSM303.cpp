
#include "MP_LSM303.h"
#define ERROR 10.0f

MP_LSM303::MP_LSM303()
	: accel(Adafruit_LSM303_Accel_Unified(54321)), mag(Adafruit_LSM303_Mag_Unified(12345))
{
}

void MP_LSM303::init()
{
#ifndef ESP8266
	while (!Serial)
		; // will pause Zero, Leonardo, etc until serial console opens
#endif

	/* Initialise the sensor */
	if (!accel.begin())
	{
		/* There was a problem detecting the LSM303 ... check your connections */
		Serial.println("Could not find a valid LSM303 sensor, check wiring!");
		while (1);
	}

	/* Enable auto-gain */
	mag.enableAutoRange(true);

	/* Initialise the sensor */
	if (!mag.begin())
	{
		/* There was a problem detecting the LSM303 ... check your connections */
		Serial.println("Ooops, no LSM303 detected ... Check your wiring!");
		while (1);
	}
}

double MP_LSM303::getAccel_X()
{
	accel.getEvent(&event);
	return event.acceleration.x;
}

double MP_LSM303::getAccel_Y()
{
	accel.getEvent(&event);
	return event.acceleration.y;
}

double MP_LSM303::getAccel_Z()
{
	accel.getEvent(&event);
	return event.acceleration.z;
}

bool MP_LSM303::checkDirection(char opt[])
{
	mag.getEvent(&event);

	float Pi = 3.14159;

	// Calculate the angle of the vector y,x
	float heading = (atan2(event.magnetic.y,event.magnetic.x) * 180) / Pi;

	// Normalize to 0-360
	if (heading < 0)
	{
		heading = 360 + heading;
	}

	if (((heading > 0.0f && heading < 0.0f + ERROR) || (heading > 360.0f - ERROR && heading < 360.0f)) && !strcmp(opt, "North"))
		return 1;
	else if (heading > 45.0f - ERROR && heading < 45.0f + ERROR && !strcmp(opt, "NorthEast"))
		return 1;
	else if (heading > 90.0f - ERROR && heading < 90.0f + ERROR && !strcmp(opt, "East"))
		return 1;
	else if (heading > 135.0f - ERROR && heading < 135.0f + ERROR && !strcmp(opt, "SouthEast"))
		return 1;
	else if (heading > 180.0f - ERROR && heading < 180.0f + ERROR && !strcmp(opt, "South"))
		return 1;
	else if (heading > 225.0f - ERROR && heading < 225.0f + ERROR && !strcmp(opt, "SouthWest"))
		return 1;
	else if (heading > 270.0f - ERROR && heading < 270.0f + ERROR && !strcmp(opt, "West"))
		return 1;
	else if (heading > 315.0f - ERROR && heading < 315.0f + ERROR && !strcmp(opt, "NorthWest"))
		return 1;
	else
		return 0;
}

double MP_LSM303::getMag_X()
{
	mag.getEvent(&event);
	return event.magnetic.x;
}

double MP_LSM303::getMag_Y()
{
	mag.getEvent(&event);
	return event.magnetic.y;
}

double MP_LSM303::getMag_Z()
{
	mag.getEvent(&event);
	return event.magnetic.z;
}