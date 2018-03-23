#ifndef MP_GROVE_ULTRASONIC_RANGER_H
#define MP_GROVE_ULTRASONIC_RANGER_H

#include <Arduino.h>

class MP_GROVE_Ultrasonic_Ranger//: MP_Led
{
  public:
	MP_GROVE_Ultrasonic_Ranger(uint8_t pin);

	void init();
	double getDistance() ;

  private:
	uint8_t pin;

};

#endif
