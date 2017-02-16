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

void MP_GeneralLed::blink(uint16_t frequency) const
{
	digitalWrite(this->pin, HIGH);
	delay(1000 / frequency);
	digitalWrite(this->pin, LOW);
	delay(1000 / frequency);
}

void MP_GeneralLed::dim(uint8_t percentage) const
{
	analogWrite(this->pin, 255 * percentage); /* Only PWM Pin */
}
