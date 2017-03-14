#ifndef MP_LSM303_H
#define MP_LSM303_H

//#include "MP_Mag.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303.h>



class MP_LSM303// : MP_Mag
{
  public:
	 
	 ~MP_LSM303() {};
	 int accel_x(char opt[], float treshold, uint8_t unit)  ;
	 int accel_y(char opt[], float treshold, uint8_t unit)  ;
	 int accel_z(char opt[], float treshold, uint8_t unit) ;
	 int compass(char opt[])  ;
	 int mag_x(char opt[], float treshold, uint8_t unit)  ;
	 int mag_y(char opt[], float treshold, uint8_t unit)  ;
	 int mag_z(char opt[], float treshold, uint8_t unit) ;
	 void init() ;
	

  private:
	  Adafruit_LSM303 lsm;
      sensors_event_t event;
	 

};

#endif