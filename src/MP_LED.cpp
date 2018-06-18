#include "MP_LED.h"

MP_LED::MP_LED(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_LED::init()
{
    pinMode(this->pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_LED::on(int brightness)
{
    analogWrite(this->pin, map(brightness, 0, 100, 0, 255));
    MP_Log::i(tag,"On");
}

void MP_LED::off()
{
    digitalWrite(this->pin, LOW);
    MP_Log::i(tag,"Off");
}
