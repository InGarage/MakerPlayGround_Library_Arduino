#include "MP_TMP007.h"

MP_TMP007::MP_TMP007(const String &tag)
:   tag(tag)
{
}

void MP_TMP007::init() 
{

	
	if (!tmp007.begin()) 
	{
		Serial.println("Could not find a valid TMP007 sensor, check wiring!");
		MP_Log::e(tag,"Could not find a valid TMP007 sensor, check wiring!");
		while (1);
	}
	MP_Log::i(tag,"Ready");

}


double MP_TMP007::getTemperature() 
{
    MP_Log::i(tag,tmp007.readObjTempC());
	return tmp007.readObjTempC() ;
}


