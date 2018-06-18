#include "MP_MakerPlayground7Seg.h"

uint8_t digits[] = {0b00111111, 0b00000110, 0b01011011, 0b01001111, 0b01100110, 0b01101101, 0b01111101, 0b00000111, 0b01111111, 0b01101111};

MP_MakerPlayground7Seg::MP_MakerPlayground7Seg(uint8_t tx, uint8_t rx,const String &tag)
    : serial(SoftwareSerial(rx,tx)),tag(tag)
{
}

void MP_MakerPlayground7Seg::init()
{
    serial.begin(9600);
    MP_Log::i(tag,"Ready");
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
    serial.write((byte)0x7f);
    serial.write((byte)3);
    if (negative) {
        serial.write((byte)0b01000000);
        for (int i=2; i>=0; i--) 
        {
            if (dot & (1 << i))
                serial.write((byte)(digits[tmp[i]] | 0b10000000));
            else
                serial.write((byte)(digits[tmp[i]]));
        }
    } else {
        for (int i=3; i>=0; i--) 
        {
            if (dot & (1 << i))
                serial.write((byte)(digits[tmp[i]] | 0b10000000));
            else
                serial.write((byte)(digits[tmp[i]]));
        }
    }
    serial.write((byte)0);
    serial.write((byte)'\r');
    serial.write((byte)'\n');
}

void MP_MakerPlayground7Seg::sendInvalid()
{
    serial.write((byte)0x7f);
    serial.write((byte)3);
    serial.write((byte)0b01000000);
    serial.write((byte)0b01000000);
    serial.write((byte)0b01000000);
    serial.write((byte)0b01000000);
    serial.write((byte)0b00000000);
    serial.write((byte)'\r');
    serial.write((byte)'\n');
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
            sendData(num, 0x00, false);
        } else {
            sendInvalid();
        }
    } else {
        num = -num;
        if (num < 10) {
            sendData(num * 100, 0x04, true);
        } else if (num < 100) {
            sendData(num * 10, 0x02, true);
        } else if (num < 1000) {
            sendData(num, 0x00, true);
        } else {
            sendInvalid();
        }
    }
}

void MP_MakerPlayground7Seg::showValue(double value)
{
    showFloat(value);
    MP_Log::i(tag,String("Show Value: ") + value);
}

void MP_MakerPlayground7Seg::showData(double value)
{
    showFloat(value);
    MP_Log::i(tag,String("Show Data: ") + value);
}

void MP_MakerPlayground7Seg::off()
{
    serial.write((byte)0x7f);
    serial.write((byte)3);
    serial.write((byte)0b00000000);
    serial.write((byte)0b00000000);
    serial.write((byte)0b00000000);
    serial.write((byte)0b00000000);
    serial.write((byte)0b00000000);
    serial.write((byte)'\r');
    serial.write((byte)'\n');
    MP_Log::i(tag,"Off");
}