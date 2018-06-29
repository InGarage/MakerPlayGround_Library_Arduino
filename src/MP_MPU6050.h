#ifndef MP_MPU6050_H
#define MP_MPU6050_H

//#include "MP_Mag.h"
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <MPU6050.h>
#include "MP_Log.h"

class MP_MPU6050 // : MP_Mag
{
  public:
    MP_MPU6050(const String &tag);
	~MP_MPU6050(){};

	void init();

	double getAccel_X();
	double getAccel_Y();
	double getAccel_Z();
	double getAccel_Magnitude();

	double getGyro_X();
	double getGyro_Y();
	double getGyro_Z();

	bool checkDirection(char opt[]);

  private:
	MPU6050 accelgyro;
	const String tag;
};

#endif
