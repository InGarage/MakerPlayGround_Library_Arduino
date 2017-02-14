#ifndef MP_GENERALLED_H
#define MP_GENERALLED_H

//#include "MP_Led.h"
#include <Arduino.h>

class MP_GeneralLed //: MP_Led
{
  public:
    MP_GeneralLed(uint8_t pin);
    ~MP_GeneralLed() {};

    void on() const;
    void off() const;

  private:
    uint8_t pin;
};

#endif