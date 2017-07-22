#ifndef MP_PIR_H
#define MP_PIR_H

#include <Arduino.h>

class MP_PIR //: MP_Led
{
  public:
	MP_PIR(uint8_t pin);
	~MP_PIR() {};

	double getValue() ;
	void init() ;


  private:
	uint8_t pin;

};

#endif