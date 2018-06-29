#ifndef MP_Waterlvl_H
#define MP_Waterlvl_H

#include <Arduino.h>
#include "MP_Log.h"

class MP_Waterlvl
{
public:
	MP_Waterlvl(uint8_t pin,const String &tag) ;
	~MP_Waterlvl() {};
    
    void init();

	bool isWet();
	bool isDry();
	
private:
	uint8_t pin;
	const String tag;
};

#endif
