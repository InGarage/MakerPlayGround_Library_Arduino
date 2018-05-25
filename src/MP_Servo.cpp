#include "MP_Servo.h"

MP_Servo::MP_Servo(uint8_t pin)
  : pin(pin)
{
  
}

void MP_Servo::init()
{
	myservo.attach(pin);
}

void MP_Servo::moveto(int degree)
{
	myservo.write(degree);
}

