#ifndef MP_BME280_H
#define MP_BME280_H

#include "MP_Baro.h"
#include "Adafruit_Sensor.h"
#include "Adafruit_BME280.h"
#include <Arduino.h>
#include <Wire.h>
#include <SPI.h>
#define SEALEVELPRESSURE_HPA (1013.25)


class MP_BME280 : MP_Baro
{
  public:
	  MP_BME280();
	 ~MP_BME280() {};

	 int pressure(char opt[], char treshold[], char unit[]) const ;
	 int attitude(char opt[], char treshold[], char unit[]) const ;
	 int humidity(char opt[], char treshold[], char unit[]) const ;
	 int temp(char opt[], char treshold[], char unit[]) const ;

  private:
	  Adafruit_BME280 bme;
	 

};

#endif