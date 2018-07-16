#ifndef MP_LED_H
#define MP_LED_H

#include <Arduino.h>
class MP_LED //: MP_Led
{
  public:
    MP_LED(uint8_t pin);

    void init();
    void on(int brightness);
    void off();

  private:
    uint8_t pin;
};

#endif