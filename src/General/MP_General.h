#ifndef MP_GENERNAL_H
#define MP_GENERNAL_H

#include <Arduino.h>

class MP_General
{
  public:
	virtual int delay(uint16_t time) const = 0;


	
};

#endif