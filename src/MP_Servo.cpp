#include "MP_Servo.h"

MP_Servo::MP_Servo(uint8_t pin,const String &tag)
  : pin(pin),tag(tag)
{
  
}

void MP_Servo::init()
{
	myservo.attach(pin);
	MP_Log::i(tag,"Ready");
}

void MP_Servo::moveto(int degree)
{
	myservo.write(degree);
	MP_Log::i(tag,String("Moving to ") + degree);
}

