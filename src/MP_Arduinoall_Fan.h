#ifndef MP_ARDUINOALL_FAN_H
#define MP_ARDUINOALL_FAN_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_Arduinoall_Fan //: MP_DCMotor
{
  public:
    MP_Arduinoall_Fan(uint8_t inA, uint8_t inB,const String &tag);
    ~MP_Arduinoall_Fan(){};

    void init();
    void on(char dir[], int speed);
    // void reverse();
    // void set_speed(uint8_t speed);
    void off();

  private:
    uint8_t inA;
    uint8_t inB;
    const String tag;
};

#endif