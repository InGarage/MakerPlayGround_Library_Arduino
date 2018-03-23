#include "MP_GROVE_Sound.h"

MP_GROVE_Sound::MP_GROVE_Sound(uint8_t pin)
	:pin(pin)
{

}

void MP_GROVE_Sound::init() 
{
	pinMode(this->pin, INPUT);

}

double MP_GROVE_Sound::getSoundLevel() 
{ 
    long sum = 0;
    for(int i=0; i<8; i++)
    {
        sum += analogRead(this->pin);
    }
    sum >>= 3;
    Serial.println(sum);
    delay(10);
	
	return 100.0*sum/1024.0;
}


