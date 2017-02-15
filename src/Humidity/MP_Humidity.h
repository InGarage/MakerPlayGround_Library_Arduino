#ifndef MP_HUMIDITY_H
#define MP_HUMIDITY_H

#include <Arduino.h>

class MP_Humidity
{
  public:
	virtual int humidity(char opt[], char treshold[], char unit[]) const = 0;
	virtual int temp(char opt[], char treshold[], char unit[]) const = 0;


};

#endif