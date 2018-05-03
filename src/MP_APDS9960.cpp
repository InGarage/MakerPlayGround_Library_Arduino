#include "MP_APDS9960.h"

MP_APDS9960::MP_APDS9960()
    : adps(SparkFun_APDS9960())
{
}

void MP_APDS9960::init()
{
    // Initialize APDS-9960 (configure I2C and initial values)
    if ( apds.init() ) {
        Serial.println(F("APDS-9960 initialization complete"));
    } else {
        Serial.println(F("Something went wrong during APDS-9960 init!"));
    }

    // Adjust the Proximity sensor gain
    if ( !apds.setProximityGain(PGAIN_2X) ) {
        Serial.println(F("Something went wrong trying to set PGAIN"));
    }

    // Start running the APDS-9960 proximity sensor (no interrupts)
    if ( apds.enableProximitySensor(false) ) {
        Serial.println(F("Proximity sensor is now running"));
    } else {
        Serial.println(F("Something went wrong during sensor init!"));
    }

    // Start running the APDS-9960 gesture sensor engine
    if ( apds.enableGestureSensor(false) ) {
        Serial.println(F("Gesture sensor is now running"));
    } else {
        Serial.println(F("Something went wrong during gesture sensor init!"));
    }
}

double MP_APDS9960::getDistance()
{
    uint8_t proximity_data;
    if ( !apds.readProximity(proximity_data) ) {
        Serial.println(F("Error reading proximity value"));
        return 255;
    } else {
        return proximity_data;
    }
}

bool MP_APDS9960::isGestureDetected(char c[])
{
     if ( apds.isGestureAvailable() ) {
         int gesture = apds.readGesture();
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
    return (apds.readGesture() == DIR_NONE);
}