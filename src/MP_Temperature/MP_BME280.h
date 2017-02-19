#ifndef MP_BME280_H
#define MP_BME280_H

#include "MP_Temp.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>



class MP_BME280 : MP_Temp
{
  public:
	  MP_BME280();
	 ~MP_BME280() {};

	 int checkTemp(char opt[], float treshold, uint8_t unit)const ;
	 void init() const;
	

  private:
	  Adafruit_BME280 bme;
	 

};

#endif