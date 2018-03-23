#include "MP_GROVE_Ultrasonic_Ranger.h"

MP_GROVE_Ultrasonic_Ranger::MP_GROVE_Ultrasonic_Ranger(uint8_t pin)
  : pin(pin)
{
  
}

void MP_GROVE_Ultrasonic_Ranger::init() 
{
	pinMode(this->pin,INPUT);
}

double MP_GROVE_Ultrasonic_Ranger::getDistance()
{
    pinMode(this->pin, OUTPUT);
	digitalWrite(this->pin, LOW);
	delayMicroseconds(2);
	digitalWrite(this->pin, HIGH);
	delayMicroseconds(5);
	digitalWrite(this->pin,LOW);
	pinMode(this->pin,INPUT);
	duration = pulseIn(this->pin,HIGH);
	RangeInCentimeters = duration/29/2;
    return RangeInCentimeters;
}

double MP_GROVE_Ultrasonic_Ranger::getTemperature() 
{
	// return -40 + (analogRead(pin)/1023.0) * (125 - (-40));
    return analogRead(pin)/1023.0) * 165 - 40;
}


