#ifndef MP_SoilWithEnable_H
#define MP_SoilWithEnable_H

#include <Arduino.h>
#include "MP_Log.h"
class MP_SoilWithEnable
{
  public:
	MP_SoilWithEnable(uint8_t data, uint8_t en,const String &tag);

	double getPercent();
	void init();

  private:
	uint8_t data;
    uint8_t en;
    const String tag;

};

#endif