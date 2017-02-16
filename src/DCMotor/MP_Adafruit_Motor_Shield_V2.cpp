#include "MP_Adafruit_Motor_Shield_V2.h"

MP_Adafruit_Motor_Shield_V2::MP_Adafruit_Motor_Shield_V2(uint8_t pin)
  : pin(pin)
{
	AFMS = Adafruit_MotorShield();
	*myMotor = AFMS.getMotor(pin);
	Serial.begin(9600);
	AFMS.begin();
	direction = 1;
	myMotor->run(FORWARD);
	myMotor->setSpeed(150);
	myMotor->run(RELEASE);

}

void MP_Adafruit_Motor_Shield_V2::on(uint8_t direction, uint8_t speed) const
{
	myMotor->setSpeed(speed);
	if (direction == 1)
	{
		myMotor->run(FORWARD);
	}
	else if (direction == 2)
	{
		myMotor->run(BACKWARD);
	}
}
void MP_Adafruit_Motor_Shield_V2::reverse() const
{
	if (direction == 1)
	{
		direction = 2;
		myMotor->run(BACKWARD);
	}
	else if (direction == 2)
	{
		direction = 1;
		myMotor->run(FORWARD);
	}
}
void MP_Adafruit_Motor_Shield_V2::set_speed(uint8_t speed) const 
{
	myMotor->setSpeed(speed);
}
void MP_Adafruit_Motor_Shield_V2::stop() const
{
	myMotor->setSpeed(0);
}


