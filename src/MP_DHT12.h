
#ifndef MP_DHT12_H
#define MP_DHT12_H

//#include "MP_Baro.h"
#include "dht_dplasa.h"

#include <Arduino.h>
#include <Wire.h>


class MP_DHT12 //: MP_Baro
{
  public:
	 MP_DHT12();
	 double getHumidity();
	 double getTemperature();
	 void init();

  private:
	 dht12 sensor;

};

#endif
