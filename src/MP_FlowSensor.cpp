#include "MP_FlowSensor.h"

volatile unsigned int MP_FlowSensor::pulseCount = 0;

MP_FlowSensor::MP_FlowSensor(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_FlowSensor::init()
{
    this->calibrationFactor = 98.0;
    this->flowRate          = 0.0;
    this->flowMilliLitres   = 0;
    this->totalMilliLitres  = 0;
    this->oldTime           = millis();
    this->flowChange        = 0;

    pulseCount = 0;

    pinMode(this->pin, INPUT_PULLUP);
    enableInterrupt(this->pin | PINCHANGEINTERRUPT, MP_FlowSensor::interruptHandler, FALLING);

    MP_Log::i(tag, "Ready");
}

void MP_FlowSensor::update()
{
    if (millis() - oldTime > 100)
    {
        disableInterrupt(this->pin | PINCHANGEINTERRUPT);

        unsigned long totalTimeMillis = (millis() - oldTime);
        this->flowMilliLitres = this->pulseCount / this->calibrationFactor;
        this->flowRate = this->flowMilliLitres * 1000.0 / totalTimeMillis;  // mL per second
        this->totalMilliLitres = this->totalMilliLitres + this->flowMilliLitres;
        this->flowChange = (flowMilliLitres > 10); // change will be detected if the flow is more than 10 mL

        this->oldTime = millis();
        pulseCount = 0;
        enableInterrupt(this->pin | PINCHANGEINTERRUPT, MP_FlowSensor::interruptHandler, FALLING);
    }
}

int MP_FlowSensor::isWaterFlow()
{
    return this->flowChange;
}

double MP_FlowSensor::getFlow_Rate()
{
    return this->flowRate;
}

double MP_FlowSensor::getTotal_Water_Amount()
{
    return this->totalMilliLitres;
}

static void MP_FlowSensor::interruptHandler()
{
    pulseCount++;
}