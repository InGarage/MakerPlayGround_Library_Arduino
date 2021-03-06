#include "MP_APDS9960.h"
#include "SparkFun_APDS9960.h"

MP_APDS9960::MP_APDS9960(const String &tag)
    : apds(SparkFun_APDS9960()),tag(tag)
{
}

void MP_APDS9960::init()
{
    // Initialize APDS-9960 (configure I2C and initial values)
    if ( apds.init() ) {
        //Serial.println(F("APDS-9960 initialization complete"));
        MP_Log::i(tag,"APDS-9960 initialization complete");
    } else {
        //Serial.println(F("Something went wrong during APDS-9960 init!"));
        MP_Log::e(tag,"Something went wrong during APDS-9960 init!");
    }

    // Adjust the Proximity sensor gain
    if ( !apds.setProximityGain(PGAIN_2X) ) {
        MP_Log::e(tag,"Something went wrong trying to set PGAIN");
        //Serial.println(F("Something went wrong trying to set PGAIN"));
    }

    // Start running the APDS-9960 proximity sensor (no interrupts)
    if ( apds.enableProximitySensor(false) ) {
        //Serial.println(F("Proximity sensor is now running"));
        MP_Log::i(tag,"Proximity sensor is now running");
    } else {
        //Serial.println(F("Something went wrong during sensor init!"));
        MP_Log::e(tag,"Something went wrong during sensor init!");

    }

//    // Start running the APDS-9960 gesture sensor engine
//    if ( apds.enableGestureSensor(false) ) {
//        Serial.println(F("Gesture sensor is now running"));
//    } else {
//        Serial.println(F("Something went wrong during gesture sensor init!"));
//    }
}

double MP_APDS9960::getDistance()
{
    uint8_t x;
    if ( !apds.readProximity(x) ) {
        return 999999;
        //Serial.println(F("Error reading proximity value"));
        //return 255;
    } else {
        double distance = 0.000858238872*x*x - 0.233873883*x + 26.3131278;
        if(x > 136 || distance < 10 ) {
            return 10;
        }
        else if (distance > 20) {
            return 20;
        }
        //Serial.println(distance);
        MP_Log::i(tag,distance);
        return distance;
    }
}

bool MP_APDS9960::isGestureDetected(char c[])
{
     if ( apds.isGestureAvailable() ) {
         int gesture = apds.readGesture();
         MP_Log::i(tag,(gesture == DIR_UP && c[0] == 'U')
                                   || (gesture == DIR_DOWN && c[0] == 'D')
                                   || (gesture == DIR_LEFT && c[0] == 'L')
                                   || (gesture == DIR_RIGHT && c[0] == 'R')
                                   || (gesture == DIR_NEAR && c[0] == 'N')
                                   || (gesture == DIR_FAR && c[0] == 'F'));
         return (gesture == DIR_UP && c[0] == 'U') 
            || (gesture == DIR_DOWN && c[0] == 'D')
            || (gesture == DIR_LEFT && c[0] == 'L')
            || (gesture == DIR_RIGHT && c[0] == 'R')
            || (gesture == DIR_NEAR && c[0] == 'N')
            || (gesture == DIR_FAR && c[0] == 'F');
     }
}

bool MP_APDS9960::isGestureNotDetected()
{
    MP_Log::i(tag,"Not Dectected");
    return (apds.readGesture() == DIR_NONE);
}