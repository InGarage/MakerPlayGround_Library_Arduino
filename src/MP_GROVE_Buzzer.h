#ifndef MP_GROVE_BUZZER_H
#define MP_GROVE_BUZZER_H

#include <Arduino.h>

class MP_GROVE_Buzzer //: MP_Button
{
  public:
	MP_GROVE_Buzzer(uint8_t pin);
	~MP_GROVE_Buzzer(){};

	void init();
    void beep();
	
  private:
	uint8_t pin;
};

#endif
