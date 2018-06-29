#ifndef MP_HC_SR501_H
#define MP_HC_SR501_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_HC_SR501 //: MP_Led
{
  public:
	MP_HC_SR501(uint8_t pin,const String &tag);

	int isDetected();
	int isNotDetected();
	void init();

  private:
	uint8_t pin;
	const String tag;

};

#endif