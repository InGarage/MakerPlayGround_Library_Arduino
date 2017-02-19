#ifndef MP_LSM9DS1_H
#define MP_LSM9DS1_H

#include "MP_Gyro.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#include <SparkFunLSM9DS1.h>
#define LSM9DS1_M	0x1E // Would be 0x1C if SDO_M is LOW
#define LSM9DS1_AG	0x6B // Would be 0x6A if SDO_AG is LOW

// Earth's magnetic field varies by location. Add or subtract 
// a declination to get a more accurate heading. Calculate 
// your's here:
// http://www.ngdc.noaa.gov/geomag-web/#declination
#define DECLINATION -8.58 // Declination (degrees) in Boulder, CO.



class MP_LSM9DS1 : MP_Gyro
{
  public:

	 ~MP_LSM9DS1() {};

	 int rotate_x(char opt[], float treshold, uint8_t unit) const ;
	 int rotate_y(char opt[], float treshold, uint8_t unit) const ;
	 int rotate_z(char opt[], float treshold, uint8_t unit) const;
	 void init() const;
	

  private:
	  LSM9DS1 imu;

};

#endif