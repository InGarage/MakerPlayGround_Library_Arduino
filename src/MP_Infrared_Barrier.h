#ifndef MP_INFRARED_BARRIER_H
#define MP_INFRARED_BARRIER_H

#include <Arduino.h>

class MP_Infrared_Barrier //: MP_Led
{
  public:
	MP_Infrared_Barrier(uint8_t pin);

	int isDetected();
	int isNotDetected();
	void init();

  private:
	uint8_t pin;

};

#endif