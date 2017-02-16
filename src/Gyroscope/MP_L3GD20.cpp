#include "MP_L3GD20.h"



MP_L3GD20::MP_L3GD20()
{
	Serial.begin(9600);
	if (!gyro.begin(gyro.L3DS20_RANGE_250DPS)) {
		Serial.println("Could not find a valid L3GD20 sensor, check wiring!");
		while (1);
	}

}

int MP_L3GD20::rotate_x(char opt[], float treshold, uint8_t unit) const
{
	gyro.read();
	if (!strcmp(opt, ">="))
	{
		if (gyro.data.x >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (gyro.data.x > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (gyro.data.x == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (gyro.data.x < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (gyro.data.x <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (gyro.data.x != treshold)
			return 1;
		else
			return 0;
	}	
	
	
}
int MP_L3GD20::rotate_y(char opt[], float treshold, uint8_t unit) const
{
	gyro.read();
	if (!strcmp(opt, ">="))
	{
		if (gyro.data.y >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (gyro.data.y > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (gyro.data.y == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (gyro.data.y < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (gyro.data.y <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (gyro.data.y != treshold)
			return 1;
		else
			return 0;
	}


}
int MP_L3GD20::rotate_z(char opt[], float treshold, uint8_t unit) const
{
	gyro.read();
	if (!strcmp(opt, ">="))
	{
		if (gyro.data.z >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (gyro.data.z > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (gyro.data.z == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (gyro.data.z < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (gyro.data.z <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (gyro.data.z != treshold)
			return 1;
		else
			return 0;
	}


}


