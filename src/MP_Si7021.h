#ifndef MP_SI7021_H
#define MP_SI7021_H

//#include "MP_Humidity.h"
#include "Adafruit_Si7021.h"
#include <Arduino.h>


class MP_Si7021 //: MP_Humidity
{
  public:

	 ~MP_Si7021() {};
	 int humidity(char opt[], float treshold, uint8_t unit)  ;
	 int checkTemp(char opt[], float treshold, uint8_t unit)  ;
	 void init() ;
	

  private:
	  Adafruit_Si7021 sensor ;
	 

};

#endif