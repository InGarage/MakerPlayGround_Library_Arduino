#include "MP_LSM9DS1.h"
#define G 9.80665f
#define LSM9DS1_M	0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG	0x6B // Would be 0x6A if SDO_AG is LOW

// Earth's magnetic field varies by location. Add or subtract 
// a declination to get a more accurate heading. Calculate 
// your's here:
// http://www.ngdc.noaa.gov/geomag-web/#declination
#define DECLINATION -8.58 // Declination (degrees) in Boulder, CO.


MP_LSM9DS1::MP_LSM9DS1()
{

	imu.settings.device.commInterface = IMU_MODE_I2C;
	imu.settings.device.mAddress = LSM9DS1_M;
	imu.settings.device.agAddress = LSM9DS1_AG;

}


void MP_LSM9DS1::init() const
{
	// Before initializing the IMU, there are a few settings
	// we may need to adjust. Use the settings struct to set
	// the device's communication mode and addresses:

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
	Serial.println(imu.ax) ;
	if (!strcmp(opt, ">="))
	{
		if (imu.calcAccel(imu.ax)*G >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcAccel(imu.ax)*G> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.ax)*G== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcAccel(imu.ax)*G< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.ax)*G<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.ax)*G!= treshold)
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
		if (imu.calcAccel(imu.ay)*G>= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcAccel(imu.ay)*G> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.ay)*G== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcAccel(imu.ay)*G< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.ay)*G<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.ay)*G!= treshold)
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
		if (imu.calcAccel(imu.az)*G >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcAccel(imu.az)*G> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcAccel(imu.az)*G == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcAccel(imu.az)*G< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcAccel(imu.az)*G <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcAccel(imu.az)*G != treshold)
			return 1;
		else
			return 0;
	}
}
 int MP_LSM9DS1::slop_x(char opt[], float treshold, uint8_t unit) const {}
 int MP_LSM9DS1::slop_y(char opt[], float treshold, uint8_t unit) const {}
 int MP_LSM9DS1::slop_z(char opt[], float treshold, uint8_t unit) const {}
 int MP_LSM9DS1::tap() const{}
 int MP_LSM9DS1::doubletap() const {}
 int MP_LSM9DS1::freefall() const {}
	


