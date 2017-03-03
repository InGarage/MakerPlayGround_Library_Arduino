#ifndef MP_TMP007_H
#define MP_TMP007_H

//#include "MP_Temp.h"
#include <Wire.h>
#include "Adafruit_TMP007.h"
#include <Arduino.h>


class MP_TMP007  //: MP_Temp
{
  public:
	 ~MP_TMP007() {};

	
	 int checkTemp(char opt[], float treshold, uint8_t unit) const ;
	 void init() const;

  private:
	  Adafruit_TMP007 tmp007;
	 

};

#endif