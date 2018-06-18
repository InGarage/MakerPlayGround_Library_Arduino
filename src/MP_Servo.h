#ifndef MP_Servo_H
#define MP_Servo_H

#include <Arduino.h>
#include <Servo.h>
#include "MP_Log.h"
class MP_Servo//: MP_Led
{
  public:
	MP_Servo(uint8_t pin,const String &tag);

	void moveto(int degree);
	void init();

  private:
	uint8_t pin;
	Servo myservo;
    const String tag;
};

#endif
