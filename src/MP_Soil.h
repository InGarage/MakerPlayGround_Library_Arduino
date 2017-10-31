#ifndef MP_Soil_H
#define MP_Soil_H

#include <Arduino.h>

class MP_Soil//: MP_Led
{
  public:
	MP_Soil(uint8_t pin);

	double getHumid();
	void init();

  private:
	uint8_t pin;

};

#endif
