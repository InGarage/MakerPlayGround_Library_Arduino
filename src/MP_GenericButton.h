#ifndef MP_GENERICBUTTON_H
#define MP_GENERICBUTTON_H

#include <Arduino.h>

class MP_GenericButton //: MP_Button
{
  public:
	MP_GenericButton(uint8_t pin);
	MP_GenericButton(){};

	void init();
	boolean isReleased();
	boolean isPressed();
	
  private:
	uint8_t pin;
};

#endif
