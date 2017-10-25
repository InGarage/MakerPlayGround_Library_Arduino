
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

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
}


double MP_MPU6050::getAccel_X()
{
	return accelgyro.getAccelerationX();	
}

double MP_MPU6050::getAccel_Y()
{
	return accelgyro.getAccelerationY();	
}

double MP_MPU6050::getAccel_Z()
{
	return accelgyro.getAccelerationZ();	
}

double MP_MPU6050::getGyro_X() 
{
	return accelgyro.getRotationX();
}

double MP_MPU6050::getGyro_Y() 
{
	return accelgyro.getRotationY();
}
double MP_MPU6050::getGyro_Z() 
{
	return accelgyro.getRotationZ();
}
