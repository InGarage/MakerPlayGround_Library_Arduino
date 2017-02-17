#include "MP_PAM8302A.h"

MP_PAM8302A::MP_PAM8302A(uint8_t SDPin, uint8_t speakerPin)
	:speakerPin(speakerPin)
{
	tmrpcm.speakerPin = speakerPin; 
	Serial.begin(115200);

	if (!SD.begin(SDPin)) {  // see if the card is present and can be initialized:
		Serial.println("SD fail");
		return;   // don't do anything more if not
	}
	else {
		Serial.println("SD ok");
	}
	
}

void MP_PAM8302A::play(char file[], float vol) const
{

	if (vol < 12.5f)
		volLevel = 0;
	else if (vol < 25.0f)
		volLevel = 1;
	else if (vol < 37.5f)
		volLevel = 2;
	else if (vol < 50f)
		volLevel = 3;
	else if (vol < 62.5f)
		volLevel = 4;
	else if (vol < 75f)
		volLevel = 5;
	else if (vol < 87.5f)
		volLevel = 6;
	else if (vol <= 100.0f)
		volLevel = 7;
	

	tmrpcm.play(file);
	tmrpcm.setVolume(volLevel);
}

void MP_PAM8302A::volUp() const
{
	tmrpcm.volume(1);
}
void MP_PAM8302A::volDown() const
{
	tmrpcm.volume(0);

}
void MP_PAM8302A::setVol(float vol) const
{
	if (vol < 12.5f)
		volLevel = 0;
	else if (vol < 25.0f)
		volLevel = 1;
	else if (vol < 37.5f)
		volLevel = 2;
	else if (vol < 50f)
		volLevel = 3;
	else if (vol < 62.5f)
		volLevel = 4;
	else if (vol < 75f)
		volLevel = 5;
	else if (vol < 87.5f)
		volLevel = 6;
	else if (vol <= 100.0f)
		volLevel = 7;

	tmrpcm.setVolume(volLevel);
}
void MP_PAM8302A::stop() const
{
	tmrpcm.disable();
}
void MP_PAM8302A::beep(uint16_t hz, uint16_t dur) const
{
	
	digitalWrite(speakerPin, HIGH);
	delayMicroseconds(0.5f*(1 / Hz)*1000000);
	digitalWrite(speakerPin, LOW);
}
