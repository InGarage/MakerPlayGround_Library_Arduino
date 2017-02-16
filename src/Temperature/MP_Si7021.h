#ifndef MP_SI7021_H
#define MP_SI7021_H

#include "MP_Temp.h"
#include "Adafruit_Si7021.h"
#include <Arduino.h>


class MP_Si7021 : MP_Temp
{
  public:
	  MP_Si7021();
	 ~MP_Si7021() {};

	 int temp(char opt[], float treshold, uint8_t unit) const ;
	

  private:
	  Adafruit_Si7021 sensor ;
	 

};

#endif