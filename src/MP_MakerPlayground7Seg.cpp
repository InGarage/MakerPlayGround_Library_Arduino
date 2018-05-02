#include "MP_MakerPlayground7Seg.h"

uint8_t digits[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

MP_MakerPlayground7Seg::MP_MakerPlayground7Seg(uint8_t pin) 
    : serial(SendOnlySoftwareSerial(pin))
{
}

void MP_MakerPlayground7Seg::init()
{
    serial.begin(9600);
}

void MP_MakerPlayground7Seg::sendData(int num, uint8_t dot, bool negative)
{
    // split digit
    uint8_t tmp[4];
    for (int i=0; i<4; i++)
    {
        tmp[i] = num % 10;
        num = num / 10;
    }

    // send
    serial.print((byte)0x7f);
    serial.print((byte)3);
    if (negative) {
        serial.print((byte)0b01000000);
        for (int i=2; i>=0; i--) 
        {
            if (dot && (1 << i))
                serial.print((byte)(digits[tmp[i]] | 0b10000000));
            else
                serial.print((byte)(digits[tmp[i]]));
        }
    } else {
        for (int i=3; i>=0; i--) 
        {
            if (dot && (1 << i))
                serial.print((byte)(digits[tmp[i]] | 0b10000000));
            else
                serial.print((byte)(digits[tmp[i]]));
        }
    }
    serial.print((byte)0);
}

void MP_MakerPlayground7Seg::sendInvalid()
{
    serial.print((byte)0x7f);
    serial.print((byte)3);
    serial.print((byte)0b01000000);
    serial.print((byte)0b01000000);
    serial.print((byte)0b01000000);
    serial.print((byte)0b01000000);
    serial.print((byte)0b00000000);
    serial.print((byte)0);
}

void MP_MakerPlayground7Seg::showFloat(double num)
{
    if (num >= 0) {
        if (num < 10) {
            sendData(num * 1000, 0x08, false);
        } else if (num < 100) {
            sendData(num * 100, 0x04, false);
        } else if (num < 1000) {
            sendData(num * 10, 0x02, false);
        } else if (num < 10000) {
            sendData(num, 0x01, false);
        } else {
            sendInvalid();
        }
    } else {
        num = -num;
        if (num < 1) {
            sendData(num * 100, 0x04, true);
        } else if (num < 10) {
            sendData(num * 10, 0x02, true);
        } else if (num < 100) {
            sendData(num, 0x01, true);
        } else {
            sendInvalid();
        }
    }
}

void MP_MakerPlayground7Seg::showValue(double value)
{
    showFloat(value);
}

void MP_MakerPlayground7Seg::showData(double value)
{
    showFloat(value);
}

void MP_MakerPlayground7Seg::off()
{
    serial.print((byte)0x7f);
    serial.print((byte)0);
    serial.print((byte)0b00000000);
    serial.print((byte)0b00000000);
    serial.print((byte)0b00000000);
    serial.print((byte)0b00000000);
    serial.print((byte)0b00000000);
    serial.print((byte)0);
}
