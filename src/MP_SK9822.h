#ifndef MP_SK9822_H
#define MP_SK9822_H

#include <Arduino.h>
#include "APA102.h"

class MP_SK9822
{
public:
    MP_SK9822(uint8_t data, uint8_t clk);

    void init();
    void on(int red, int green, int blue, int brightness);
    void off();

private:
    void startFrame();
    void sendColor(uint8_t red, uint8_t green, uint8_t blue, uint8_t brightness = 31);
    void endFrame(uint16_t count);
    void transfer(uint8_t count);

private:
    uint8_t data;
    uint8_t clk;
};

#endif