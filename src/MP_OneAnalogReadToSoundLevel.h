#ifndef MP_OneAnalogReadToSoundLevel_H
#define MP_OneAnalogReadToSoundLevel_H

#include <Arduino.h>
#define MP_OneAnalogReadToSoundLevel_MAX_ARRAY 20

class MP_OneAnalogReadToSoundLevel//: MP_Led
{
  public:
	MP_OneAnalogReadToSoundLevel(uint8_t pin);

	double getSoundLevel();
	void init();

  private:
	uint8_t pin;
	double normal;
};

#endif
