#include "MP_MAX4466.h"

MP_MAX4466::MP_MAX4466(uint8_t pin,const String &tag)
	:pin(pin),tag(tag)
{

}

void MP_MAX4466::init() 
{
	pinMode(pin, INPUT);
    MP_Log::i(tag,"Ready");
}

double MP_MAX4466::getSoundLevel() 
{ 
	Serial.println(100.0*analogRead(pin)/1024.0);
	MP_Log::i(tag,100.0*analogRead(pin)/1024.0);
	return 100.0*analogRead(pin)/1024.0;
}


