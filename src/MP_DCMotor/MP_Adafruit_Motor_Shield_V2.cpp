#include "MP_Adafruit_Motor_Shield_V2.h"

 uint8_t direction; 

MP_Adafruit_Motor_Shield_V2::MP_Adafruit_Motor_Shield_V2(uint8_t pin)
	
{
	myMotor = AFMS.getMotor(pin);
	
}


void MP_Adafruit_Motor_Shield_V2::init() const
{
	
	AFMS.begin();
	direction = 1;

}

void MP_Adafruit_Motor_Shield_V2::on(char dir[], uint8_t speed) const
  
{
	

	if(!strcmp(dir,"CW"))
		direction = 1 ;
	else if(!strcmp(dir,"CW"))
		direction = 2 ;

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


