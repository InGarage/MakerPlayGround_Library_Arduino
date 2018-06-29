#ifndef MP_Soil_H
#define MP_Soil_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_Soil//: MP_Led
{
  public:
	MP_Soil(uint8_t pin,const String &tag);

	double getHumidity();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
