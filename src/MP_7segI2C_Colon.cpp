#include "MP_7segI2C_Colon.h"

MP_7segI2C_Colon::MP_7segI2C_Colon(uint8_t clk, uint8_t dio,const String &tag)
	: display(TM1637Display(clk, dio)), data(0), brightness(7),tag(tag)
{
}

void MP_7segI2C_Colon::init()
{
    MP_Log::i(tag,"Ready");
}

void MP_7segI2C_Colon::showValue(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showFloat(value, true);
	MP_Log::i(tag,String("Show Value: ") + value);
}

void MP_7segI2C_Colon::showData(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showNumberDec((int) value);
	MP_Log::i(tag,String("Show Data: ") + value);
}

void MP_7segI2C_Colon::setBrightness(char c[])
{
	brightness = (int) c[0] - '0';
	display.setBrightness(brightness, true);
	display.showNumberDec((int) data);
}

void MP_7segI2C_Colon::off()
{
	uint8_t data[] = {0x0, 0x0, 0x0, 0x0};
	display.setBrightness(brightness, false);
	display.setSegments(data);
	MP_Log::i(tag,"Off");
}
