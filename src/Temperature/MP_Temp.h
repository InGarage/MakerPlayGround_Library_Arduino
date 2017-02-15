#ifndef MP_TEMP_H
#define MP_TEMP_H

#include <Arduino.h>

class MP_Temp
{
  public:
     virtual int temp(char opt[], char treshold[], char unit[]) const = 0;


};

#endif