#ifndef MP_DELAY_H
#define MP_DELAY_H

#include "MP_General.h"
#include <Arduino.h>




class MP_DELAY : MP_General
{
  public:
	  MP_L3GD20();
	 ~MP_L3GD20() {};

	 int delay(uint16_t time) const ;



};

#endif