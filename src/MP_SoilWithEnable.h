#ifndef MP_SoilWithEnable_H
#define MP_SoilWithEnable_H

#include <Arduino.h>

class MP_SoilWithEnable
{
  public:
	MP_SoilWithEnable(uint8_t data, uint8_t en);

	double getPercent();
	void init();

  private:
	uint8_t data;
    uint8_t en;

};

#endif