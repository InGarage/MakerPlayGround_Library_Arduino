#include "MP_Arduinoall_Fan.h"

MP_Arduinoall_Fan::MP_Arduinoall_Fan(uint8_t inA, uint8_t inB)
    : inA(inA), inB(inB)
{
}

void MP_Arduinoall_Fan::init()
{
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
}

void MP_Arduinoall_Fan::on(char dir[], int speed)
{
    speed = map(speed, 0, 100, 0, 255);
    if (strcmp(dir, "Forward") == 0)
    {
        analogWrite(inA, speed);
        digitalWrite(inB, LOW);
    }
    else
    {
        digitalWrite(inA, LOW);
        analogWrite(inB, speed);
    }
}

void MP_Arduinoall_Fan::off()
{
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
}