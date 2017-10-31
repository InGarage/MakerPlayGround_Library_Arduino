#ifndef MP_7SEGI2C_H
#define MP_7SEGI2C_H

#include <Arduino.h>
#include "TM1637Display.h"

class MP_7segI2C //: MP_Led
{
  public:
	MP_7segI2C(uint8_t clk, uint8_t dio);
	~MP_7segI2C(){};

	void init();
	void showValue(double value);
	void showData(double value);
	void setBrightness(char c[]);
	void off();

  private:
	int data;
	int brightness;
	TM1637Display display;
};

#endif
