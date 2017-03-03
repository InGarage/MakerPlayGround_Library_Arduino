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
	 int accel_x(char opt[], float treshold, uint8_t unit) const ;
	 int accel_y(char opt[], float treshold, uint8_t unit) const ;
	 int accel_z(char opt[], float treshold, uint8_t unit) const;
	 int compass(char opt[]) const ;
	 int mag_x(char opt[], float treshold, uint8_t unit) const ;
	 int mag_y(char opt[], float treshold, uint8_t unit) const ;
	 int mag_z(char opt[], float treshold, uint8_t unit) const;
	 void init() const;
	

  private:
	  Adafruit_LSM303 lsm;
      sensors_event_t event;
	 

};

#endif