#include "MP_Piezo.h"

MP_Piezo::MP_Piezo(uint8_t pin)
    : pin(pin)
{
}

void MP_Piezo::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_Piezo::beep(double frequency)
{
    tone(this->pin, frequency);
    delay(100);
    noTone(this->pin);
}

void MP_Piezo::play(double frequency, double duration)
{
    tone(this->pin, frequency);
    delay(duration * 1000);
    noTone(this->pin);
}