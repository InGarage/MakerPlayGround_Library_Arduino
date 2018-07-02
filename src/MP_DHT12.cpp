#include "MP_DHT12.h"

  // what digital pin we're connected to

// Uncomment whatever type you're using!

 MP_DHT12::MP_DHT12(const String &tag)
	 :sensor(dht12(0x5c)),tag(tag)
{
}


void MP_DHT12::init() 
{
    dht::ReadStatus chk = sensor.read();
    if(chk != dht::OK)
    {
        MP_Log::e(tag,"Oops! DHT12 reading failed");
	    while(1) delay(20);
	}
	MP_Log::i(tag,"Ready");
}

double MP_DHT12::getTemperature()
{
    delay(50);
    dht::ReadStatus chk = sensor.read();
    if(chk == dht::OK)
    {
        double value = (double)sensor.getTemperature()/10.0;
        Serial.println(value);
        MP_Log::i(tag,value);
	    return value;
	}
    return 9999999999;
}


double MP_DHT12::getHumidity() 
{
    delay(50);
    dht::ReadStatus chk = sensor.read();
    if(chk == dht::OK)
    {
        double value = (double)sensor.getHumidity()/10.0;
        MP_Log::i(tag,value);
	    return value;
	}
    return 9999999999;
}
