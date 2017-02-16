#ifndef MP_BME280_H
#define MP_BME280_H

#include "MP_Humidity.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>



class MP_BME280 : MP_Humidity
{
  public:
	  MP_BME280();
	 ~MP_BME280() {};

	 int humidity(char opt[], float treshold, uint8_t unit)const ;
	

  private:
	  Adafruit_BME280 bme;
	 

};

#endif