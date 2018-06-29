

#include "MP_Adafruit_MotorShield.h"

 uint8_t direction; 

MP_Adafruit_MotorShield::MP_Adafruit_MotorShield(const String &tag)
	: tag(tag)
{
	myMotor = AFMS.getMotor(1);
	
}


void MP_Adafruit_MotorShield::init() {
	
	AFMS.begin();
	direction = 1;
	MP_Log::i(tag,"Ready");

}

void MP_Adafruit_MotorShield::on(char dir[], uint8_t speed)   
{
	
    MP_Log::i(tag,"On");
	if(!strcmp(dir,"CW"))
		direction = 1 ;
	else if(!strcmp(dir,"CW"))
		direction = 2 ;

	myMotor->setSpeed(speed);	
	if (direction == 1)
	{
		myMotor->run(FORWARD);
		MP_Log::i(tag,"Forward");
	}
	else if (direction == 2)
	{
		myMotor->run(BACKWARD);
		MP_Log::i(tag,"Backward");
	}
}
void MP_Adafruit_MotorShield::reverse() {
	
	if (direction == 1)
	{
		direction = 2;
		myMotor->run(BACKWARD);
		MP_Log::i(tag,"Backward");

	}
	else if (direction == 2)
	{
		direction = 1;
		myMotor->run(FORWARD);
		MP_Log::i(tag,"Forward");
	}
	
}
void MP_Adafruit_MotorShield::set_speed(uint8_t speed)  
{
	myMotor->setSpeed(speed);
	MP_Log::i(tag,String("Speed: ") + speed);

}
void MP_Adafruit_MotorShield::off() {
	myMotor->setSpeed(0);
	MP_Log::i(tag,"Off");
}

