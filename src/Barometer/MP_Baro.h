#ifndef MP_BARO_H
#define MP_BARO_H

#include <Arduino.h>

class MP_Baro
{
  public:
	virtual int pressure(char opt[],char treshold[],char unit[]) const = 0;
	virtual int attitude(char opt[], char treshold[], char unit[]) const = 0;
	virtual int humidity(char opt[], char treshold[], char unit[]) const = 0;
	virtual int temp(char opt[], char treshold[], char unit[]) const = 0;


};

#endif