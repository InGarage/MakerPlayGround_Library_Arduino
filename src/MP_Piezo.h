#ifndef MP_PIEZO_H
#define MP_PIEZO_H

#include <Arduino.h>

class MP_Piezo
{
  public:
    MP_Piezo(uint8_t pin);
    ~MP_Piezo(){};

    void init();
    void beep(double frequency);
    void play(double frequency, double duration);

  private:
    uint8_t pin;
};

#endif