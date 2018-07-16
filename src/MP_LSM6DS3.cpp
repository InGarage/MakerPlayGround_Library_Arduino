#include "MP_LSM6DS3.h"

MP_LSM6DS3::MP_LSM6DS3()
    : imu(LSM6DS3(I2C_MODE, 0x6A))
{
}

void MP_LSM6DS3::init()
{
    if (imu.begin() != IMU_SUCCESS)
    {
        //Serial.println("Can't detect LSM6DS3. Please check connection!!!");
        while(1);

    }
}

double MP_LSM6DS3::getAccel_X()
{
    return imu.readFloatAccelX();
}

double MP_LSM6DS3::getAccel_Y()
{
    return imu.readFloatAccelY();
}

double MP_LSM6DS3::getAccel_Z()
{
    return imu.readFloatAccelZ();
}

double MP_LSM6DS3::getAccel_Magnitude()
{
    return sqrt(imu.readFloatAccelX() * imu.readFloatAccelX()
        + imu.readFloatAccelY() * imu.readFloatAccelY()
        + imu.readFloatAccelZ() * imu.readFloatAccelZ());
}

double MP_LSM6DS3::getGyro_X()
{
    return imu.readFloatGyroX();
}

double MP_LSM6DS3::getGyro_Y()
{
    return imu.readFloatGyroY();
}

double MP_LSM6DS3::getGyro_Z()
{
    return imu.readFloatGyroZ();
}