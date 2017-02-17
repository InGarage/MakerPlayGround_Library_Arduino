#include "MP_LSM9DS1.h"




MP_LSM9DS1::MP_LSM9DS1()
{

	Serial.begin(115200);

	// Before initializing the IMU, there are a few settings
	// we may need to adjust. Use the settings struct to set
	// the device's communication mode and addresses:
	imu.settings.device.commInterface = IMU_MODE_I2C;
	imu.settings.device.mAddress = LSM9DS1_M;
	imu.settings.device.agAddress = LSM9DS1_AG;
	// The above lines will only take effect AFTER calling
	// imu.begin(), which verifies communication with the IMU
	// and turns it on.
	if (!imu.begin())
	{
		Serial.println("Failed to communicate with LSM9DS1.");
		Serial.println("Double-check wiring.");
		Serial.println("Default settings in this sketch will " \
			"work for an out of the box LSM9DS1 " \
			"Breakout, but may need to be modified " \
			"if the board jumpers are.");
		while (1)
			;
	}

}



int MP_LSM9DS1::accel_x(char opt[], float treshold, uint8_t unit) const
{
	imu.readAccel();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcAccel(imu.ax) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcAccel(imu.ax)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.ax)== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcAccel(imu.ax)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.ax)<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.ax)!= treshold)
			return 1;
		else
			return 0;
	}	
	
	
}

int MP_LSM9DS1::accel_y(char opt[], float treshold, uint8_t unit) const
{
	imu.readAccel();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcAccel(imu.ay)>= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcGyro(imu.gy)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.ay)== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcGyro(imu.gy)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.ay)<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.ay)!= treshold)
			return 1;
		else
			return 0;
	}


}

int MP_LSM9DS1::accel_z(char opt[], float treshold, uint8_t unit) const
{
	imu.readAccel();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcAccel(imu.az) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcAccel(imu.az)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.az) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcAccel(imu.az)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.az) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.az) != treshold)
			return 1;
		else
			return 0;
	}


}

