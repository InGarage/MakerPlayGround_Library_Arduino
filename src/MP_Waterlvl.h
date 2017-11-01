#ifndef MP_Waterlvl_H
#define MP_Waterlvl_H

//#include "MP_Button.h"
#include <Arduino.h>



class MP_Waterlvl//: MP_Button
{
  public:
	 MP_Waterlvl(uint8_t pin) ;
	 ~MP_Waterlvl() {};

	  int isWet()  ;
	  void init() ;
	 

   private:
	  uint8_t pin;

};

#endif
