
#ifndef MP_HC_SR04P_H
#define MP_HC_SR04P_H


#include <Arduino.h>
#include "MP_Log.h"




class MP_HC_SR04P //: MP_Baro
{
  public:

	 MP_HC_SR04P(uint8_t echo ,uint8_t trig,const String &tag ) ;

	 double getDistance() ;
	 void init() ;

  private:
	  uint8_t trig;
	  uint8_t echo;
	  const String tag;
	 

};

#endif
