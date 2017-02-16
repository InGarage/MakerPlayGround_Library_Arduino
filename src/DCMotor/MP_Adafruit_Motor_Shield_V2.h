#ifndef MP_ADAFRUIT_MOTOR_SHIELD_V2_H
#define MP_ADAFRUIT_MOTOR_SHIELD_V2_H

#include "MP_DCMotor.h"
#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"
#include <Arduino.h>

class MP_Adafruit_Motor_Shield_V2 : MP_DCMotor
{
  public:
	  MP_Adafruit_Motor_Shield_V2(uint8_t pin); /* port motor sheild */
	~MP_Adafruit_Motor_Shield_V2() {};
	void on(uint8_t direction, uint8_t speed) const;
	void reverse() const;
	void set_speed(uint8_t speed) const;
	void stop() const;
	

  private:
	uint8_t direction;  /* 1 = CW = FORWARD , 2 = CCW = BACKWARD */
	Adafruit_MotorShield AFMS;
	Adafruit_DCMotor *myMotor;

};

#endif