#ifndef MP_GROVE_PIR_H
#define MP_GROVE_PIR_H

#include <Arduino.h>

class MP_GROVE_PIR
{
  public:
    MP_GROVE_PIR(uint8_t pin);

    void init();
    int isDetected();
    int isNotDetected();

  private:
    uint8_t pin;
};

#endif