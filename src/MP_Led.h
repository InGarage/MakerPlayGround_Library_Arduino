#ifndef MP_LED_H
#define MP_LED_H

#include <Arduino.h>

class MP_Led
{
  public:
    virtual void on() const = 0;
    virtual void off() const = 0;
};

#endif