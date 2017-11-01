#ifndef MP_LSM303_H
#define MP_LSM303_H

//#include "MP_Mag.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_LSM303_U.h>

class MP_LSM303 // : MP_Mag
{
  public:
	MP_LSM303();
	~MP_LSM303(){};

	void init();
	
	double getAccel_X();
	double getAccel_Y();
	double getAccel_Z();
	
	double getMag_X();
	double getMag_Y();
	double getMag_Z();

	bool checkDirection(char opt[]);

  private:
	Adafruit_LSM303_Accel_Unified accel;
	Adafruit_LSM303_Mag_Unified mag;
	sensors_event_t event;
};

#endif