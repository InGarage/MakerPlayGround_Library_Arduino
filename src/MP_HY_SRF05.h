#ifndef MP_HY_SRF05_H
#define MP_HY_SRF05_H

#include <Arduino.h>

class MP_HY_SRF05 //: MP_Baro
{
  	public:

		MP_HY_SRF05(uint8_t echo ,uint8_t trig) ;

		double getDistance() ;
		void init() ;

  	private:
		uint8_t trig;
		uint8_t echo;
};

#endif