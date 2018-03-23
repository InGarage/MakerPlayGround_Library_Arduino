#ifndef MP_GROVE_BUTTON_H
#define MP_GROVE_BUTTON_H

#include <Arduino.h>

class MP_GROVE_Button //: MP_Button
{
  public:
	MP_GROVE_Button(uint8_t pin);
	~MP_GROVE_Button(){};

	void init();
	boolean isReleased();
	boolean isPressed();
	
  private:
	uint8_t pin;
};

#endif
