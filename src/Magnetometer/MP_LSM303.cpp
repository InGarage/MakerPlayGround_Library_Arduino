#include "MP_LSM303.h"


MP_LSM303::MP_LSM303()
{
#ifndef ESP8266
	while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif
	Serial.begin(9600);
	if (!lsm.begin()) {
		Serial.println("Could not find a valid LSM303 sensor, check wiring!");
		while (1);
	}

}

int MP_LSM303::compass(char opt[]) const
{
	
	sensors_event_t event;
	mag.getEvent(&event);

	float Pi = 3.14159;

	// Calculate the angle of the vector y,x
	float heading = (atan2(event.magnetic.y, event.magnetic.x) * 180) / Pi;

	// Normalize to 0-360
	if (heading < 0)
	{
		heading = 360 + heading;
	}
	if ((heading == 0.0f || heading == 360.0f ) && !strcmp(opt, "N"))
		return 1;
	else if (heading == 45.0f && !strcmp(opt, "NE"))
		return 1;
	else if (heading == 90.0f && !strcmp(opt, "E"))
		return 1;
	else if (heading == 135.0f && !strcmp(opt, "SE"))
		return 1;
	else if (heading == 180.0f && !strcmp(opt, "S"))
		return 1;
	else if (heading == 225.0f && !strcmp(opt, "SW"))
		return 1;
	else if (heading == 270.0f && !strcmp(opt, "W"))
		return 1;
	else if (heading == 315.0f && !strcmp(opt, "NW"))
		return 1;
	else
		return 0;

}

int MP_LSM303::mag_x(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.magData.x >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.magData.x > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.magData.x == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.magData.x < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.magData.x <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.magData.x != treshold)
			return 1;
		else
			return 0;
	}	
	
	
}
int MP_LSM303::mag_y(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.magData.y >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.magData.y > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.magData.y == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.magData.y < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.magData.y <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.magData.y != treshold)
			return 1;
		else
			return 0;
	}


}
int MP_LSM303::mag_z(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.magData.z >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.magData.z > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.magData.z == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.magData.z < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.magData.z <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.magData.z != treshold)
			return 1;
		else
			return 0;
	}


}


