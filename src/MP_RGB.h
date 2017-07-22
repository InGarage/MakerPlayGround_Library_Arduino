#ifndef MP_RGB_H
#define MP_RGB_H
#define commonAnode true

//#include "MP_Button.h"
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"

class MP_RGB //: MP_Button
{
  public:
	 MP_RGB() ;
	 ~MP_RGB() {};

	  void init() ;
	 

   private:
	  Adafruit_TCS34725 tcs ;

};

#endif