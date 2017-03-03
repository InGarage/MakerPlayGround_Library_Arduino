#ifndef MP_L3GD20_H
#define MP_L3GD20_H

//#include "MP_Gyro.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_L3GD20_U.h>



class MP_L3GD20 //: MP_Gyro
{
  public:
	
	 ~MP_L3GD20() {};

	 int rotate_x(char opt[], float treshold, uint8_t unit) const ;
	 int rotate_y(char opt[], float treshold, uint8_t unit) const ;
	 int rotate_z(char opt[], float treshold, uint8_t unit) const;
	 void init() const;
	

  private:
	  Adafruit_L3GD20_Unified gyro = Adafruit_L3GD20_Unified(20);
	  sensors_event_t event;
	 

};

#endif