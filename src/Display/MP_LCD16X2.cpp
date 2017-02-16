#include "MP_LCD16X2.h"

MP_LCD16X2::MP_LCD16X2()
{
	lcd.begin(16, 2);
}

void MP_LCD16X2::backlight_on() const
{
	lcd.setBacklight(HIGH);
}

void MP_LCD16X2::backlight_off() const
{
	lcd.setBacklight(LOW);
}

void MP_LCD16X2::show(char text[]) const
{
	lcd.print(text);
}

void MP_LCD16X2::clear() const
{
	lcd.clear();
}
