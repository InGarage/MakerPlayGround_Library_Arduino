#ifndef MP_Servo_H
#define MP_Servo_H

#include <Arduino.h>
#include <Servo.h>
class MP_Servo//: MP_Led
{
  public:
	MP_Servo(uint8_t pin);

	void moveto(int degree);
	void init();

  private:
		uint8_t pin;
		Servo myservo;
		int previous_degree;
};

#endif
