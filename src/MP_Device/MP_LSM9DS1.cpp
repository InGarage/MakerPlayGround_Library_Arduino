#include "MP_LSM9DS1.h"
#define G 9.80665f
#define ERROR 10.0f
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
    Serial.println(imu.calcAccel(imu.ax)*G ) ;
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

int MP_LSM9DS1::compass(char opt[]) const
{
	imu.readMag();
	float heading=0;
	if (-imu.my == 0)
		heading = (-imu.mx < 0) ? PI : 0;
	else
		heading = atan2(-imu.mx, -imu.my);

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
	Serial.println(heading) ;

	if (((heading > 0.0f && heading < 0.0f + ERROR )|| (heading > 360.0f - ERROR && heading < 360.0f ) ) && !strcmp(opt, "N"))
		return 1;
	else if (heading > 45.0f - ERROR && heading < 45.0f + ERROR && !strcmp(opt, "NE"))
		return 1;
	else if (heading > 90.0f - ERROR && heading < 90.0f + ERROR && !strcmp(opt, "E"))
		return 1;
	else if (heading > 135.0f - ERROR && heading < 135.0f + ERROR && !strcmp(opt, "SE"))
		return 1;
	else if (heading > 180.0f - ERROR && heading < 180.0f + ERROR && !strcmp(opt, "S"))
		return 1;
	else if (heading > 225.0f - ERROR && heading < 225.0f + ERROR && !strcmp(opt, "SW"))
		return 1;
	else if (heading > 270.0f - ERROR && heading < 270.0f + ERROR && !strcmp(opt, "W"))
		return 1;
	else if (heading > 315.0f - ERROR && heading < 315.0f + ERROR && !strcmp(opt, "NW"))
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

int MP_LSM9DS1::rotate_x(char opt[], float treshold, uint8_t unit) const
{
	imu.readGyro();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcGyro(imu.gx) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcGyro(imu.gx)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcGyro(imu.gx)== treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcGyro(imu.gx)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcGyro(imu.gx)<= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcGyro(imu.gx)!= treshold)
			return 1;
		else
			return 0;
	}	
	
	
}

int MP_LSM9DS1::rotate_y(char opt[], float treshold, uint8_t unit) const
{
	imu.readGyro();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcGyro(imu.gy) >= treshold)
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
		if (imu.calcGyro(imu.gy) == treshold)
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
		if (imu.calcGyro(imu.gy) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcGyro(imu.gy) != treshold)
			return 1;
		else
			return 0;
	}


}

int MP_LSM9DS1::rotate_z(char opt[], float treshold, uint8_t unit) const
{
	imu.readGyro();
	if (!strcmp(opt, ">="))
	{
		if (imu.calcGyro(imu.gz) >= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, ">"))
	{
		if (imu.calcGyro(imu.gz)> treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "="))
	{
		if (imu.calcGyro(imu.gz) == treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<"))
	{
		if (imu.calcGyro(imu.gz)< treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "<="))
	{
		if (imu.calcGyro(imu.gz) <= treshold)
			return 1;
		else
			return 0;
	}
	else if (!strcmp(opt, "!="))
	{
		if (imu.calcGyro(imu.gz) != treshold)
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
	


