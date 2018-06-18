#ifndef MP_LSM6DS3_H
#define MP_LSM6DS3_H

#include <Arduino.h>
#include "SparkFunLSM6DS3.h"
#include "Wire.h"
#include "MP_Log.h"

class MP_LSM6DS3
{
public:
		MP_LSM6DS3(const String &tag);

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
		const String tag;
};

#endif
