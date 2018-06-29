#ifndef MP_TCS34725_H
#define MP_TCS34725_H
#define commonAnode true

//#include "MP_Button.h"
#include <Arduino.h>
#include <Wire.h>
#include "Adafruit_TCS34725.h"
#include "MP_Log.h"

class MP_TCS34725 //: MP_Button
{
  public:
	 MP_TCS34725(const String &tag) ;
	 ~MP_TCS34725() {};
	 int isColor(char color[]);
	  void init() ;
 private:
    const String tag;
	  
};

#endif