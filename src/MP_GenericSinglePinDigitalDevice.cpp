#include "MP_GenericSinglePinDigitalDevice.h"

MP_GenericSinglePinDigitalDevice::MP_GenericSinglePinDigitalDevice(uint8_t pin)
    : pin(pin)
{
}

void MP_GenericSinglePinDigitalDevice::init()
{
    pinMode(pin, OUTPUT);
}

void MP_GenericSinglePinDigitalDevice::on()
{
    digitalWrite(pin, HIGH);
}

void MP_GenericSinglePinDigitalDevice::off()
{
    digitalWrite(pin, LOW);
}