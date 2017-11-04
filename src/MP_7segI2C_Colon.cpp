#include "MP_7segI2C_Colon.h"

MP_7segI2C_Colon::MP_7segI2C_Colon(uint8_t clk, uint8_t dio)
	: display(TM1637Display(clk, dio)), data(0), brightness(7)
{
}

void MP_7segI2C_Colon::init()
{
}

void MP_7segI2C_Colon::showValue(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showFloat(value, true);
}

void MP_7segI2C_Colon::showData(double value)
{
	data = value;
	display.setBrightness(brightness, true);
	display.showNumberDec((int) value);
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
}
