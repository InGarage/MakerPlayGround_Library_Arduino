#include "MP_Si7021.h"


MP_Si7021::MP_Si7021(const String &tag)
:   tag(tag)
{
}

void MP_Si7021::init() 
{
	sensor = Adafruit_Si7021();

	if (!sensor.begin()) {
		// Serial.println("Could not find a valid Si7021 sensor, check wiring!");
		MP_Log::e(tag,"Could not find a valid Si7021 sensor, check wiring!");
		while (1);
	}
	MP_Log::i(tag,"Ready");

}

double MP_Si7021::getTemperature() 
{
    MP_Log::i(tag,sensor.readTemperature());
	return sensor.readTemperature() ;
}


double MP_Si7021::getHumidity() 
{
    MP_Log::i(tag,sensor.readHumidity());
	return sensor.readHumidity() ;
}
