#include "MP_RGB_LED_CC.h"

MP_RGB_LED_CC::MP_RGB_LED_CC(uint8_t r, uint8_t g, uint8_t b,const String &tag)
    : r(r), g(g), b(b),tag(tag)
{
}

void MP_RGB_LED_CC::init()
{
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_RGB_LED_CC::on(int red, int green, int blue, int brightness)
{
    MP_Log::i(tag,"On");
    red = 255 - (red*brightness)/100.0;
    green = 255 - (red*brightness)/100.0;
    blue = 255 - (red*brightness)/100.0;
    analogWrite(r, red);
    analogWrite(g, green);
    analogWrite(b, blue);
}

void MP_RGB_LED_CC::off()
{
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
    MP_Log::i(tag,"Off");
}