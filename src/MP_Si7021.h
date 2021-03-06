#ifndef MP_SI7021_H
#define MP_SI7021_H

//#include "MP_Humidity.h"
#include "Adafruit_Si7021.h"
#include <Arduino.h>
#include "MP_Log.h"


class MP_Si7021 //: MP_Humidity
{
  public:
     MP_Si7021(const String &tag);
	 ~MP_Si7021() {};
	 double getHumidity()  ;
	 double getTemperature()  ;
	 void init() ;
	

  private:
	  Adafruit_Si7021 sensor ;
	  const String tag;
	 

};

#endif