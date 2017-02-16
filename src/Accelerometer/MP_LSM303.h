#ifndef MP_LSM303_H
#define MP_LSM303_H

#include "MP_Accel.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303.h>



class MP_LSM303 : MP_Accel
{
  public:
	  MP_LSM303();
	 ~MP_LSM303() {};

	 int accel_x(char opt[], float treshold, uint8_t unit) const ;
	 int accel_y(char opt[], float treshold, uint8_t unit) const ;
	 int accel_z(char opt[], float treshold, uint8_t unit) const;
	

  private:
	  Adafruit_LSM303 lsm;
	 

};

#endif