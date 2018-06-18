#include "MP_Piezo.h"

MP_Piezo::MP_Piezo(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_Piezo::init()
{
    pinMode(this->pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_Piezo::beep()
{
    tone(this->pin, 2000);
    delay(100);
    noTone(this->pin);
    MP_Log::i(tag,"Beep");
}

void MP_Piezo::play(double frequency, double duration)
{
    tone(this->pin, frequency);
    delay(duration * 1000);
    noTone(this->pin);
    MP_Log::i(tag,"Play tone");
}