#ifndef MP_MAKERPLAYGROUND7SEG_H
#define MP_MAKERPLAYGROUND7SEG_H

#include <Arduino.h>
#include "SendOnlySoftwareSerial.h"

class MP_MakerPlayground7Seg
{
public:
	MP_MakerPlayground7Seg(uint8_t pin);

	void init();
	void showValue(double num);
	void showData(double num);
	void off();

private:
	void sendInvalid();
    void showFloat(double num);
    void sendData(int num, uint8_t dot, bool negative);

	SendOnlySoftwareSerial serial;
};

#endif
