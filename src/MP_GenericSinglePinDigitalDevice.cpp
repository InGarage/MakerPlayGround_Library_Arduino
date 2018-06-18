#include "MP_GenericSinglePinDigitalDevice.h"

MP_GenericSinglePinDigitalDevice::MP_GenericSinglePinDigitalDevice(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_GenericSinglePinDigitalDevice::init()
{
    pinMode(pin, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_GenericSinglePinDigitalDevice::on()
{
    digitalWrite(pin, HIGH);
    MP_Log::i(tag,"On");
}

void MP_GenericSinglePinDigitalDevice::off()
{
    digitalWrite(pin, LOW);
    MP_Log::i(tag,"Off");
}