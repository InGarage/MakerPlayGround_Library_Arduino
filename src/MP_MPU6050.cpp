#include "MP_MPU6050.h"
#define ERROR 10.0f

void MP_MPU6050::init()
{
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
	Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
	Fastwire::setup(400, true);
#endif

	accelgyro.initialize();
	if (!accelgyro.testConnection())
	{
		/* There was a problem detecting the LSM303 ... check your connections */
		Serial.println("Ooops, no MPU_6050 detected ... Check your wiring!");
		while (1);
	}
}

double MP_MPU6050::getAccel_X()
{
	// the default range is +-2g and the sensor is 16 bits
	return accelgyro.getAccelerationX() / 16384.0;
}

double MP_MPU6050::getAccel_Y()
{
	// the default range is +-2g and the sensor is 16 bits
	return accelgyro.getAccelerationY() / 16384.0;
}

double MP_MPU6050::getAccel_Z()
{
	// the default range is +-2g and the sensor is 16 bits
	return accelgyro.getAccelerationZ() / 16384.0;
}

double MP_MPU6050::getGyro_X()
{
	// the default range is +-250degree/sec and the sensor is 16 bits
	return accelgyro.getRotationX() / 32768.0 * 250.0;
}

double MP_MPU6050::getGyro_Y()
{
	// the default range is +-250degree/sec and the sensor is 16 bits
	return accelgyro.getRotationY() / 32768.0 * 250.0;
}

double MP_MPU6050::getGyro_Z()
{
	// the default range is +-250degree/sec and the sensor is 16 bits
	return accelgyro.getRotationZ() / 32768.0 * 250.0;
}

bool MP_MPU6050::checkDirection(char opt[])
{
	float Pi = 3.14159;

	// Calculate the angle of the vector y,x
	float heading = (atan2(getGyro_Y(), getGyro_X()) * 180) / Pi;

	// Normalize to 0-360
	if (heading < 0)
	{
		heading = 360 + heading;
	}

	Serial.println(heading);
	if (((heading > 0.0f && heading < 0.0f + ERROR) || (heading > 360.0f - ERROR && heading < 360.0f)) && !strcmp(opt, "North"))
		return 1;
	else if (heading > 45.0f - ERROR && heading < 45.0f + ERROR && !strcmp(opt, "NorthEast"))
		return 1;
	else if (heading > 90.0f - ERROR && heading < 90.0f + ERROR && !strcmp(opt, "East"))
		return 1;
	else if (heading > 135.0f - ERROR && heading < 135.0f + ERROR && !strcmp(opt, "SouthEast"))
		return 1;
	else if (heading > 180.0f - ERROR && heading < 180.0f + ERROR && !strcmp(opt, "South"))
		return 1;
	else if (heading > 225.0f - ERROR && heading < 225.0f + ERROR && !strcmp(opt, "SouthWest"))
		return 1;
	else if (heading > 270.0f - ERROR && heading < 270.0f + ERROR && !strcmp(opt, "West"))
		return 1;
	else if (heading > 315.0f - ERROR && heading < 315.0f + ERROR && !strcmp(opt, "NorthWest"))
		return 1;
	else
		return 0;
}
