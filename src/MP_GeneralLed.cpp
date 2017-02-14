#include "MP_GeneralLed.h"

MP_GeneralLed::MP_GeneralLed(uint8_t pin)
  : pin(pin)
{
  pinMode(pin, OUTPUT);
}

void MP_GeneralLed::on() const
{
  digitalWrite(this->pin, HIGH);
}

void MP_GeneralLed::off() const
{
  digitalWrite(this->pin, LOW);
}
