#include "MP_Delay.h"



void MP_Delay::init() const
{

}
int MP_Delay::delayFn(char a[],uint16_t time, char b[]) const
{
	delay(time);
	return 1;
}
