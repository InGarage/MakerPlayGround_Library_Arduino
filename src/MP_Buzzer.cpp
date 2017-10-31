#include "MP_Buzzer.h"

MP_Buzzer::MP_Buzzer(uint8_t pin)
    : pin(pin)
{
}

void MP_Buzzer::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_Buzzer::beep(double frequency)
{
    tone(this->pin, frequency);
    delay(100);
    noTone(this->pin);
}

void MP_Buzzer::play(double frequency, double duration)
{
    tone(this->pin, frequency);
    delay(duration * 1000);
    noTone(this->pin);
}