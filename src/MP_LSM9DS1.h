#ifndef MP_LSM9DS1_H
#define MP_LSM9DS1_H

//#include "MP_Accel.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>

class MP_LSM9DS1 //: MP_Accel
{
  public:
  	  MP_LSM9DS1();
	 ~MP_LSM9DS1() {};

	 int accel_x(char opt[], float treshold, uint8_t unit)  ;
	 int accel_y(char opt[], float treshold, uint8_t unit)  ;
	 int accel_z(char opt[], float treshold, uint8_t unit) ;
	 int slop_x(char opt[], float treshold, uint8_t unit)  ;
	 int slop_y(char opt[], float treshold, uint8_t unit)  ;
	 int slop_z(char opt[], float treshold, uint8_t unit)  ;
	 int rotate_x(char opt[], float treshold, uint8_t unit)  ;
	 int rotate_y(char opt[], float treshold, uint8_t unit)  ;
	 int rotate_z(char opt[], float treshold, uint8_t unit) ;
	 int compass(char opt[])  ;
	 int mag_x(char opt[], float treshold, uint8_t unit)  ;
	 int mag_y(char opt[], float treshold, uint8_t unit)  ;
	 int mag_z(char opt[], float treshold, uint8_t unit) ;
	 int tap()  ;
	 int doubletap()  ;
	 int freefall()  ;
	 void init() ;

  private:
	  LSM9DS1 imu;

};

#endif