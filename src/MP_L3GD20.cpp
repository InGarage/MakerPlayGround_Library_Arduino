
#include "MP_L3GD20.h"
#define PI 3.14159265359 

MP_L3GD20::MP_L3GD20(const String &tag)
:   tag(tag)
{
}


void MP_L3GD20::init() 
{
  /* Enable auto-ranging */
  gyro.enableAutoRange(true);
 
  /* Initialise the sensor */
  if (!gyro.begin())
  {
    /* There was a problem detecting the L3GD20 ... check your connections */
    Serial.println("Could not find a valid L3GD20 sensor, check wiring!");
    MP_Log::e(tag,"Could not find a valid L3GD20 sensor, check wiring!");
    while (1);
  }
  MP_Log::i(tag,"Ready");
}

double MP_L3GD20::getGyro_X() 
{
	
	gyro.getEvent(&event);
	MP_Log::i(tag,String("Gyro X: ") + event.gyro.x * PI);
	return event.gyro.x * PI ;	
}

double MP_L3GD20::getGyro_Y() 
{
	
	gyro.getEvent(&event);
	MP_Log::i(tag,String("Gyro Y: ") + event.gyro.y * PI);
	return event.gyro.y * PI ;	
}

double MP_L3GD20::getGyro_Z() 
{
	
	gyro.getEvent(&event);
	MP_Log::i(tag,String("Gyro Z: ") + event.gyro.z * PI);
	return event.gyro.z * PI ;	
}
