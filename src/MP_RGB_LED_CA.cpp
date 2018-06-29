#include "MP_RGB_LED_CA.h"

MP_RGB_LED_CA::MP_RGB_LED_CA(uint8_t r, uint8_t g, uint8_t b,const String &tag)
    : r(r), g(g), b(b),tag(tag)
{
}

void MP_RGB_LED_CA::init()
{
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
    MP_Log::i(tag,"Ready");
}

void MP_RGB_LED_CA::on(char color[])
{
    MP_Log::i(tag,"On");
    if (strcmp(color, "Red") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "Green") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "Blue") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "Cyan") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "Magenta") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "Yellow") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "White") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
    }
}

void MP_RGB_LED_CA::off()
{
    digitalWrite(r, HIGH);
    digitalWrite(g, HIGH);
    digitalWrite(b, HIGH);
    MP_Log::i(tag,"Off");
}
