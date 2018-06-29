#include "MP_DHT11.h"

  // what digital pin we're connected to

// Uncomment whatever type you're using!

 MP_DHT11::MP_DHT11(int pin,const String &tag)
	 :sensor(DHT(pin, 11)), pin(pin),tag(tag)
{
}


void MP_DHT11::init() 
{
	sensor.begin();
	MP_Log::i(tag,"Ready");
}

double MP_DHT11::getTemperature()
{
    MP_Log::i(tag,sensor.readTemperature());
	return sensor.readTemperature() ;
}


double MP_DHT11::getHumidity() 
{
    MP_Log::i(tag,sensor.readHumidity());
	return sensor.readHumidity() ;
}
