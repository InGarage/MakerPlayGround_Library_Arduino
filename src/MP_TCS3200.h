#ifndef MP_TCS3200_H
#define MP_TCS3200_H


#include <Arduino.h>
#include <Wire.h>
#include "MP_Log.h"
class MP_TCS3200 //: MP_Button
{
  public:
	 MP_TCS3200(uint8_t s0,uint8_t s1,uint8_t s2,uint8_t s3,uint8_t out,uint8_t LED,const String &tag) ;
	 ~MP_TCS3200() {};
	 int isColor(char color[]);
	  void init() ;

	private:
		uint8_t s0 ;
		uint8_t s1 ;
		uint8_t s2 ;
		uint8_t s3 ;
		uint8_t out ;
		uint8_t LED ;
		const String tag;

	  
};

#endif