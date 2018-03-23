#include "MP_Relay_Module.h"

MP_Relay_Module::MP_Relay_Module(uint8_t pin)
    : pin(pin)
{
}

void MP_Relay_Module::init()
{
    pinMode(this->pin, OUTPUT);
}

void MP_Relay_Module::on()
{
    digitalWrite(this->pin, HIGH);
}

void MP_Relay_Module::off()
{
    digitalWrite(this->pin, LOW);
}
