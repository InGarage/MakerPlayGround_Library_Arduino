#ifndef MP_TMP007_H
#define MP_TMP007_H

#include "MP_Temp.h"
#include "Adafruit_TMP007.h"
#include <Wire.h>
#include <Arduino.h>


class MP_TMP007 : MP_Temp
{
  public:
	  MP_TMP007();
	 ~MP_TMP007() {};

	
	 int temp(char opt[], float treshold, uint8_t unit) const ;

  private:
	  Adafruit_TMP007 tmp007;
	 

};

#endif