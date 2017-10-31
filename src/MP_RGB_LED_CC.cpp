#include "MP_RGB_LED_CC.h"

MP_RGB_LED_CC::MP_RGB_LED_CC(uint8_t r, uint8_t g, uint8_t b)
    : r(r), g(g), b(b)
{
}

void MP_RGB_LED_CC::init()
{
    pinMode(r, OUTPUT);
    pinMode(g, OUTPUT);
    pinMode(b, OUTPUT);
}

void MP_RGB_LED_CC::on(char color[])
{
    if (strcmp(color, "Red") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "Green") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "Blue") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "Cyan") == 0)
    {
        digitalWrite(r, LOW);
        digitalWrite(g, HIGH);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "Magenta") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, LOW);
        digitalWrite(b, HIGH);
    }
    else if (strcmp(color, "Yellow") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(b, LOW);
    }
    else if (strcmp(color, "White") == 0)
    {
        digitalWrite(r, HIGH);
        digitalWrite(g, HIGH);
        digitalWrite(b, HIGH);
    }
}

void MP_RGB_LED_CC::off()
{
    digitalWrite(r, LOW);
    digitalWrite(g, LOW);
    digitalWrite(b, LOW);
}