#ifndef MP_GENERICSINGLEPINDIGITALDEVICE_H
#define MP_GENERICSINGLEPINDIGITALDEVICE_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_GenericSinglePinDigitalDevice
{
public:
    MP_GenericSinglePinDigitalDevice(uint8_t pin,const String &tag);

    void init();
    void on();
    void off();

private:
    uint8_t pin;
    const String tag;
};

#endif