#ifndef MP_OneAnalogReadToPercent_H
#define MP_OneAnalogReadToPercent_H

#include <Arduino.h>
class MP_OneAnalogReadToPercent//: MP_Led
{
  public:
	MP_OneAnalogReadToPercent(uint8_t pin);

	double getPercent();
	void init();

  private:
	uint8_t pin;

};

#endif
