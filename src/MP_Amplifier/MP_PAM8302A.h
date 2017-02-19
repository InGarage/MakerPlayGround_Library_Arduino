#ifndef MP_PAM8302A_H
#define MP_PAM8302A_H

#include "MP_Amp.h"
#include <SD.h>   
#include <TMRpcm.h>    
#include <SPI.h>
#include <Arduino.h>

class MP_PAM8302A : MP_Amp
{
  public:
	 MP_PAM8302A(uint8_t SDPin, uint8_t speakerPin) ;
	~MP_PAM8302A() {};

	 void play(char file[], float vol) const  ;
	 void volUp() const  ;
	 void volDown() const  ;
	 void setVol(float vol) const  ;
	 void stop() const  ;
	 void beep(uint16_t hz, uint16_t dur) const  ;
	 void init() const;

private:
	uint8_t volLevel;
	TMRpcm tmrpcm;
	uint8_t speakerPin;
	uint8_t SDPin;
};

#endif