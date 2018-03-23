#ifndef MP_GROVE_TEMPERATURE_H
#define MP_GROVE_TEMPERATURE_H

#include <Arduino.h>

class MP_GROVE_Temperature//: MP_Led
{
  public:
	MP_GROVE_Temperature(uint8_t pin);

	double getTemperature();
	void init();

  private:
	uint8_t pin;

};

#endif
