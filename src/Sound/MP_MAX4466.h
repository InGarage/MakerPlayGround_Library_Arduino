#ifndef MP_MAX4466_H
#define MP_MAX4466_H

#include "MP_Sound.h"

#include <Arduino.h>


class MP_MAX4466 : MP_Sound
{
  public:
	  MP_MAX4466(uint8_t pin);
	 ~MP_MAX4466() {};

	
	 int vol(char opt[], float treshold) const ;



};

#endif