#ifndef MP_GENERICSINGLEPINDIGITALDEVICE_H
#define MP_GENERICSINGLEPINDIGITALDEVICE_H

#include <Arduino.h>

class MP_GenericSinglePinDigitalDevice
{
public:
    MP_GenericSinglePinDigitalDevice(uint8_t pin);

    void init();
    void on();
    void off();

private:
    uint8_t pin;
};

#endif