#ifndef MP_MPU6050_H
#define MP_MPU6050_H

//#include "MP_Mag.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <MPU6050.h>



class MP_MPU6050// : MP_Mag
{
  public:
	 
	 ~MP_MPU6050() {};
	 double getAccel_X();
	 double getAccel_Y();
	 double getAccel_Z();
	 double getGyro_X();
	 double getGyro_Y();
	 double getGyro_Z();
	 void init() ;
	

  private:
	  MPU6050 accelgyro;
	 

};

#endif
