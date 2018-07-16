#include "MP_HY_SRF05.h"


MP_HY_SRF05::MP_HY_SRF05(uint8_t echo ,uint8_t trig)
  : trig(trig), echo(echo)
{
  
}

void MP_HY_SRF05::init()  
{	
	pinMode(this->trig,OUTPUT);
	pinMode(this->echo,INPUT);
}

double MP_HY_SRF05::getDistance() {	

    long cm=0 ;
    /* loop for filter an hardware error */
    do {
        digitalWrite(trig, LOW);
        delayMicroseconds(2);
        digitalWrite(trig, HIGH);
        delayMicroseconds(10);
        digitalWrite(trig, LOW);
        cm = pulseIn(echo, HIGH) / 29.0 / 2.0 ;
  	} while(cm>3000);
    return cm;

}

