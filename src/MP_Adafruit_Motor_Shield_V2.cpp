

#include "MP_Adafruit_Motor_Shield_V2.h"

 uint8_t direction; 

MP_Adafruit_Motor_Shield_V2::MP_Adafruit_Motor_Shield_V2()
	
{
	myMotor = AFMS.getMotor(1);
	
}


void MP_Adafruit_Motor_Shield_V2::init() {
	
	AFMS.begin();
	direction = 1;

}

void MP_Adafruit_Motor_Shield_V2::on(char dir[], uint8_t speed)   
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
void MP_Adafruit_Motor_Shield_V2::reverse() {
	
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
void MP_Adafruit_Motor_Shield_V2::set_speed(uint8_t speed)  
{
	myMotor->setSpeed(speed);

}
void MP_Adafruit_Motor_Shield_V2::stop() {
	myMotor->setSpeed(0);
}

