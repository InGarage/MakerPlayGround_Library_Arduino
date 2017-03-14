
#include "MP_L3GD20.h"
#define PI 3.14159265359 


void MP_L3GD20::init() 
{

	
  Serial.begin(9600);
  
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
 
  /* Initialise the sensor */
  if (!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Could not find a valid L3GD20 sensor, check wiring!");
    while (1);
  }
}

int MP_L3GD20::rotate_x(char opt[], float treshold, uint8_t unit) 
{
	
	gyro.getEvent(&event);

	if (!strcmp(opt, ">="))
	{
		if (event.gyro.x * PI >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (event.gyro.x * PI > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (event.gyro.x * PI == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (event.gyro.x * PI < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (event.gyro.x * PI <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (event.gyro.x * PI != treshold)
			return 1;
		else
			return 0;
	}	
	
	
}
int MP_L3GD20::rotate_y(char opt[], float treshold, uint8_t unit) 
{
	gyro.getEvent(&event);

	if (!strcmp(opt, ">="))
	{
		if (event.gyro.y * PI >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (event.gyro.y * PI > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (event.gyro.y * PI == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (event.gyro.y * PI < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (event.gyro.y * PI <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (event.gyro.y * PI != treshold)
			return 1;
		else
			return 0;
	}


}
int MP_L3GD20::rotate_z(char opt[], float treshold, uint8_t unit) 
{
	gyro.getEvent(&event);
	if (!strcmp(opt, ">="))
	{
		if (event.gyro.z * PI >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (event.gyro.z * PI > treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (event.gyro.z * PI == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (event.gyro.z * PI < treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (event.gyro.z * PI <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (event.gyro.z * PI != treshold)
			return 1;
		else
			return 0;
	}


}


