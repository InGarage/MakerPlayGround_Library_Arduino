#ifndef MP_7SEGI2C_COLON_H
#define MP_7SEGI2C_COLON_H

#include <Arduino.h>
#include "TM1637Display.h"
#include "MP_Log.h"

class MP_7segI2C_Colon //: MP_Led
{
  public:
	MP_7segI2C_Colon(uint8_t clk, uint8_t dio,const String &tag);
	~MP_7segI2C_Colon(){};

	void init();
	void showValue(double value);
	void showData(double value);
	void setBrightness(char c[]);
	void off();

  private:
	int data;
	int brightness;
	TM1637Display display;
	const String tag;
};

#endif
