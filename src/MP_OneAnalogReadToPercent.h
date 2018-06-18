#ifndef MP_OneAnalogReadToPercent_H
#define MP_OneAnalogReadToPercent_H

#include <Arduino.h>
#include "MP_Log.h"
class MP_OneAnalogReadToPercent//: MP_Led
{
  public:
	MP_OneAnalogReadToPercent(uint8_t pin,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif
