#include "MP_Waterlvl.h"

MP_Waterlvl::MP_Waterlvl(uint8_t pin,const String &tag)
	:pin(pin),tag(tag)
{
}

void MP_Waterlvl::init()
{
    MP_Log::i(tag,"Ready");
}

bool MP_Waterlvl::isWet()
{
    MP_Log::i(tag,"Wet");
	return analogRead(pin) > 512;
}

bool MP_Waterlvl::isDry()
{
    MP_Log::i(tag,"Dry");
	return analogRead(pin) < 512;
}