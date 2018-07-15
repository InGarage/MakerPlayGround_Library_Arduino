#include "MP_Servo.h"

MP_Servo::MP_Servo(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  this->previous_degree = -1;
}

void MP_Servo::init()
{
	myservo.attach(pin);
	MP_Log::i(tag,"Ready");
}

void MP_Servo::moveto(int degree)
{
	// Do this to prevent the servo shaking when the degree is the same with previous.
	if (degree != previous_degree) {
		myservo.write(degree);
		previous_degree = degree;
	}
	MP_Log::i(tag,String("Moving to ") + degree);
}