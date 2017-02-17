#ifndef MP_SOUND_H
#define MP_SOUND_H

#include <Arduino.h>

class MP_Sound
{
  public:
     virtual int vol(char opt[], float treshold) const = 0;


};

#endif