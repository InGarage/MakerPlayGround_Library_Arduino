#ifndef MP_LSM6DS3_H
#define MP_LSM6DS3_H

#include <Arduino.h>
#include "SparkFunLSM6DS3.h"
#include "Wire.h"

class MP_LSM6DS3
{
public:
		MP_LSM6DS3();

		void init();

		double getAccel_X();
		double getAccel_Y();
		double getAccel_Z();
		double getAccel_Magnitude();

		double getGyro_X();
		double getGyro_Y();
		double getGyro_Z();

private:
		LSM6DS3 imu;
};

#endif
