#ifndef MP_MAX4466_H
#define MP_MAX4466_H

//#include "MP_Sound.h"

#include <Arduino.h>
#include "MP_Log.h"


class MP_MAX4466 //: MP_Sound
{
  public:
	  MP_MAX4466(uint8_t pin,const String &tag);
	 ~MP_MAX4466() {};

	
	 double getSoundLevel()  ;
	 void init() ;

  private:
	  uint8_t pin;
	  const String tag;
};

#endif