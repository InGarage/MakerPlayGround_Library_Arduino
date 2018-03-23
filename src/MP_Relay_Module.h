#ifndef MP_RELAY_MODULE_H
#define MP_RELAY_MODULE_H

#include <Arduino.h>

class MP_Relay_Module
{
  public:
    MP_Relay_Module(uint8_t pin);

    void init();
    void on();
    void off();

  private:
    uint8_t pin;
};

#endif