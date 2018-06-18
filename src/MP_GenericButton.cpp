#include "MP_GenericButton.h"


MP_GenericButton::MP_GenericButton(uint8_t pin,const String &tag)
	: pin(pin),tag(tag)
{
}

void MP_GenericButton::init()
{
	pinMode(pin, INPUT_PULLUP);
	MP_Log::i(tag,"Ready");
}

boolean MP_GenericButton::isReleased()
{
	if (digitalRead(pin) == LOW)
	{
		delay(30);
		while (digitalRead(pin) == LOW);
		delay (30);
		MP_Log::i(tag,"Released");
		return true;
	}
	return false;
}

boolean MP_GenericButton::isPressed()
{
	if (digitalRead(pin) == LOW)
	{
		delay(300);
		MP_Log::i(tag,"Pressed");
		return true;
	}
	return false;
}

// int MP_GenericButton::isMultiPressed(double press)
// {
// 	int buttonState = 0;
// 	int reading = 0;
// 	long timer = 0;
// 	int count = 0;
// 	while (1)
// 	{
// 		if (timer < 55000 && count != press)
// 		{
// 			reading = digitalRead(pin);
// 			if (buttonState != reading)
// 			{
// 				if (reading == 1)
// 				{
// 					timer = 0;
// 					count++;
// 					Serial.println(count);
// 				}
// 				else
// 				{
// 					timer = 0;
// 					delay(100);
// 				}
// 			}
// 			else if (reading == 1)
// 			{
// 				timer = 0;
// 			}
// 			buttonState = reading;
// 		}
// 		else if (count == press)
// 		{
// 			timer = 0;
// 			count = 0;
// 			Serial.println("Full count");
// 			return 1;
// 		}
// 		else
// 		{
// 			count = 0;
// 			timer = 0;
// 			Serial.println("Time out");
// 			return 0;
// 		}
// 		timer++;
// 	}
// 	return 0;
// }
