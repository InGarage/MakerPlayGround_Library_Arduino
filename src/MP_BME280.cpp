
#include "MP_BME280.h"

MP_BME280::MP_BME280(const String &tag)
	: tag(tag)
{
}

void MP_BME280::init()  
{

	if (!bme.begin()) {
		Serial.println("Could not find a valid BME280 sensor, check wiring!");
		MP_Log::e(tag,"Could not find a valid BME280 sensor, check wiring!");
		while (1);
	}
	MP_Log::i(tag,"Ready");

}

double MP_BME280::getPressure() {
    MP_Log::i(tag,bme.readPressure() / 100.0);
	return bme.readPressure() / 100.0 ;
}

double MP_BME280::getAltitude() {
    MP_Log::i(tag,bme.readAltitude(SEALEVELPRESSURE_HPA));
	return bme.readAltitude(SEALEVELPRESSURE_HPA) ;
}

double MP_BME280::getHumidity() {
    MP_Log::i(tag,bme.readHumidity());
	return bme.readHumidity() ;
}

double MP_BME280::getTemperature() {
    MP_Log::i(tag,bme.readTemperature());
	return bme.readTemperature() ;
}



