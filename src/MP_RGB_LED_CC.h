#ifndef MP_RGB_LED_CC_H
#define MP_RGB_LED_CC_H

//#include "MP_Led.h"
#include <Arduino.h>
#include "MP_Log.h"

class MP_RGB_LED_CC //: MP_Led
{
  public:
    MP_RGB_LED_CC(uint8_t r, uint8_t g, uint8_t b,const String &tag);
    ~MP_RGB_LED_CC(){};

    void init();
    void on(int red, int green, int blue, int brightness);
    void off();

  private:
    uint8_t r;
    uint8_t g;
    uint8_t b;
    const String tag;
};

#endif