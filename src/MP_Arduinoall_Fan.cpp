#include "MP_Arduinoall_Fan.h"

MP_Arduinoall_Fan::MP_Arduinoall_Fan(uint8_t inA, uint8_t inB,const String &tag)
    : inA(inA), inB(inB),tag(tag)
{
}

void MP_Arduinoall_Fan::init()
{
    pinMode(inA, OUTPUT);
    pinMode(inB, OUTPUT);
    digitalWrite(inA, LOW);
    digitalWrite(inB, LOW);
    MP_Log::i(tag,"Ready");
}

void MP_Arduinoall_Fan::on(char dir[], int speed)
{
    MP_Log::i(tag,"On");
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
    MP_Log::i(tag,"Off");
}