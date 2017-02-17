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

int MP_LSM9DS1::compass(char opt[]) const
{
	imu.readMag();
	
	if (my == 0)
		heading = (mx < 0) ? PI : 0;
	else
		heading = atan2(mx, my);

	heading -= DECLINATION * PI / 180;

	if (heading > PI) heading -= (2 * PI);
	else if (heading < -PI) heading += (2 * PI);
	else if (heading < 0) heading += 2 * PI;

	// Convert everything from radians to degrees:
	heading *= 180.0 / PI;
	// Normalize to 0-360
	if (heading < 0)
	{
		heading = 360 + heading;
	}
	if ((heading == 0.0f || heading == 360.0f ) && !strcmp(opt, "N"))
		return 1;
	else if (heading == 45.0f && !strcmp(opt, "NE"))
		return 1;
	else if (heading == 90.0f && !strcmp(opt, "E"))
		return 1;
	else if (heading == 135.0f && !strcmp(opt, "SE"))
		return 1;
	else if (heading == 180.0f && !strcmp(opt, "S"))
		return 1;
	else if (heading == 225.0f && !strcmp(opt, "SW"))
		return 1;
	else if (heading == 270.0f && !strcmp(opt, "W"))
		return 1;
	else if (heading == 315.0f && !strcmp(opt, "NW"))
		return 1;
	else
		return 0;

}

int MP_LSM9DS1::mag_x(char opt[], float treshold, uint8_t unit) const
{
	treshold *= 100; //convert unit uT to gass
	imu.readMag();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcMag(imu.mx) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcMag(imu.mx)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcMag(imu.mx)== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcMag(imu.mx)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcMag(imu.mx)<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcMag(imu.mx)!= treshold)
			return 1;
		else
			return 0;
	}	
	
	
}

int MP_LSM9DS1::mag_y(char opt[], float treshold, uint8_t unit) const
{
	treshold *= 100; //convert unit uT to gass
	imu.readMag();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcMag(imu.my) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcMag(imu.my)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcMag(imu.my) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcMag(imu.my)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcMag(imu.my) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcMag(imu.my) != treshold)
			return 1;
		else
			return 0;
	}


}

int MP_LSM9DS1::mag_z(char opt[], float treshold, uint8_t unit) const
{
	treshold *= 100; //convert unit uT to gass
	imu.readMag();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcMag(imu.mz) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcMag(imu.mz)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcMag(imu.mz) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcMag(imu.mz)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcMag(imu.mz) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcMag(imu.mz) != treshold)
			return 1;
		else
			return 0;
	}


}

