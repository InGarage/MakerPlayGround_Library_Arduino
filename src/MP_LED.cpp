#include "MP_LED.h"

MP_LED::MP_LED(uint8_t pin)
    : pin(pin)
{
}

void MP_LED::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_LED::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
}

void MP_LED::off()
{
    digitalWrite(this->pin, LOW);
}
