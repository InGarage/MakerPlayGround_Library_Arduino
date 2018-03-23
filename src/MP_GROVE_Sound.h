#ifndef MP_GROVE_SOUND_H
#define MP_GROVE_SOUND_H

//#include "MP_Sound.h"

#include <Arduino.h>


class MP_GROVE_Sound //: MP_Sound
{
  public:
	  MP_GROVE_Sound(uint8_t pin);
	 ~MP_GROVE_Sound() {};

	
	 double getSoundLevel()  ;
	 void init() ;

  private:
	  uint8_t pin;
};

#endif