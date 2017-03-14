
#include "MP_LSM303.h"
#define ERROR 10.0f

void MP_LSM303::init() 
{
#ifndef ESP8266
  while (!Serial);     // will pause Zero, Leonardo, etc until serial console opens
#endif

  Serial.println("Magnetometer Test"); Serial.println("");


  /* Initialise the sensor */
  if(!lsm.begin())
  {
    /* There was a problem detecting the LSM303 ... check your connections */
    Serial.println("Could not find a valid LSM303 sensor, check wiring!");
    while(1);

}
}


int MP_LSM303::accel_x(char opt[], float treshold, uint8_t unit) 
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
int MP_LSM303::accel_y(char opt[], float treshold, uint8_t unit) 
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
int MP_LSM303::accel_z(char opt[], float treshold, uint8_t unit) 
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


int MP_LSM303::compass(char opt[]) 
{
	
	
	lsm.read();

	float Pi = 3.14159;

	// Calculate the angle of the vector y,x
	float heading = (atan2(lsm.magData.y, lsm.magData.x) * 180) / Pi;
    
	// Normalize to 0-360
	if (heading < 0)
	{
		heading = 360 + heading;
	}

	if (((heading > 0.0f && heading < 0.0f + ERROR )|| (heading > 360.0f - ERROR && heading < 360.0f ) ) && !strcmp(opt, "N"))
		return 1;
	else if (heading > 45.0f - ERROR && heading < 45.0f + ERROR && !strcmp(opt, "NE"))
		return 1;
	else if (heading > 90.0f - ERROR && heading < 90.0f + ERROR && !strcmp(opt, "E"))
		return 1;
	else if (heading > 135.0f - ERROR && heading < 135.0f + ERROR && !strcmp(opt, "SE"))
		return 1;
	else if (heading > 180.0f - ERROR && heading < 180.0f + ERROR && !strcmp(opt, "S"))
		return 1;
	else if (heading > 225.0f - ERROR && heading < 225.0f + ERROR && !strcmp(opt, "SW"))
		return 1;
	else if (heading > 270.0f - ERROR && heading < 270.0f + ERROR && !strcmp(opt, "W"))
		return 1;
	else if (heading > 315.0f - ERROR && heading < 315.0f + ERROR && !strcmp(opt, "NW"))
		return 1;
	else
		return 0;

}

int MP_LSM303::mag_x(char opt[], float treshold, uint8_t unit) 
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
int MP_LSM303::mag_y(char opt[], float treshold, uint8_t unit) 
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
int MP_LSM303::mag_z(char opt[], float treshold, uint8_t unit) 
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


