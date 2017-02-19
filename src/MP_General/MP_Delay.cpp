#include "MP_Delay.h"



void MP_Delay::init() const
{

}
int MP_Delay::delayFn(uint16_t time) const
{
	delay(time);
	return 1;
}
