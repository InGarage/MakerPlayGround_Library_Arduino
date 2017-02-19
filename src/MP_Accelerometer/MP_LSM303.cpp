#include "MP_LSM303.h"


void MP_LSM303::init() const
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

int MP_LSM303::accel_x(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.accelData.x >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.accelData.x > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.accelData.x == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.accelData.x < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.accelData.x <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.accelData.x != treshold)
			return 1;
		else
			return 0;
	}	
	
	
}
int MP_LSM303::accel_y(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.accelData.y >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.accelData.y > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.accelData.y == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.accelData.y < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.accelData.y <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.accelData.y != treshold)
			return 1;
		else
			return 0;
	}


}
int MP_LSM303::accel_z(char opt[], float treshold, uint8_t unit) const
{
	lsm.read();
	if (!strcmp(opt, ">="))
	{
		if (lsm.accelData.z >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (lsm.accelData.z > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (lsm.accelData.z == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (lsm.accelData.z < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (lsm.accelData.z <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (lsm.accelData.z != treshold)
			return 1;
		else
			return 0;
	}


}


