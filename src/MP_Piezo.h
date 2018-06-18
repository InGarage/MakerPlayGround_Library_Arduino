#ifndef MP_PIEZO_H
#define MP_PIEZO_H

#include <Arduino.h>
#include "MP_Log.h"
class MP_Piezo
{
  public:
    MP_Piezo(uint8_t pin,const String &tag);
    MP_Piezo(){};

    void init();
    void beep();
    void play(double frequency, double duration);

  private:
    uint8_t pin;
    const String tag;
};

#endif