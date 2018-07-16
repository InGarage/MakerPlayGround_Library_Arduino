#include "MP_OneAnalogReadToSoundLevel.h"

MP_OneAnalogReadToSoundLevel::MP_OneAnalogReadToSoundLevel(uint8_t pin)
  : pin(pin)
{
  
}

void MP_OneAnalogReadToSoundLevel::init() 
{
	pinMode(this->pin,INPUT);
	normal = analogRead(pin);
	for (int i=1; i<MP_OneAnalogReadToSoundLevel_MAX_ARRAY; i++) {
        normal = 0.8 * normal + 0.2 * (analogRead(pin) - normal);
	}
}


double MP_OneAnalogReadToSoundLevel::getSoundLevel()
{
    double max = 0;
    double min = 1024;
    for (int i=0; i<MP_OneAnalogReadToSoundLevel_MAX_ARRAY; i++) {
        normal = 0.8 * normal + 0.2 * (analogRead(pin) - normal);
        delayMicroseconds(200);
        if (normal > max) max = normal;
        if (normal < min) min = normal;
	}
	double val = (fabs(max - min) - 100.0) / 300.0 * 100.0;
	if (val > 100) val = 100;
	else if (val < 0) val = 0;
	return val;
}


