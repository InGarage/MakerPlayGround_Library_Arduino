#ifndef MP_LSM9DS1_H
#define MP_LSM9DS1_H

#include "MP_Accel.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>

class MP_LSM9DS1 : MP_Accel
{
  public:
  	  MP_LSM9DS1();
	 ~MP_LSM9DS1() {};

	 int accel_x(char opt[], float treshold, uint8_t unit) const ;
	 int accel_y(char opt[], float treshold, uint8_t unit) const ;
	 int accel_z(char opt[], float treshold, uint8_t unit) const;
	 int slop_x(char opt[], float treshold, uint8_t unit) const ;
	 int slop_y(char opt[], float treshold, uint8_t unit) const ;
	 int slop_z(char opt[], float treshold, uint8_t unit) const ;
	 int tap() const ;
	 int doubletap() const ;
	 int freefall() const ;
	 void init() const;

  private:
	  LSM9DS1 imu;

};

#endif