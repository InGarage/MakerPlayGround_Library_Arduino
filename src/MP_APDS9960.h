#ifndef MP_APDS9960_H
#define MP_APDS9960_H

#include <Arduino.h>
#include <Wire.h>
#include "SparkFun_APDS9960.h"

class MP_APDS9960
{
public:
    MP_APDS9960();

    void init();
    double getDistance();
    bool isGestureDetected(char c[]);
    bool isGestureNotDetected();

private:
    SparkFun_APDS9960 apds;
};

#endif