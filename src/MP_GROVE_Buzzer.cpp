#include "MP_GROVE_Buzzer.h"

MP_GROVE_Buzzer::MP_GROVE_Buzzer(uint8_t pin)
    : pin(pin)
{
}

void MP_GROVE_Buzzer::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_GROVE_Buzzer::beep()
{
    digitalWrite(this->pin, HIGH);
    delay(100);
    digitalWrite(this->pin, LOW);
}