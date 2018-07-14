#include "MP_FlowSensor.h"

MP_FlowSensor::MP_FlowSensor(uint8_t pin,const String &tag)
    : pin(pin),tag(tag)
{
}

void MP_FlowSensor::init()
{
    this->calibrationFactor = 0.2381;
    this->flowRate          = 0.0;
    this->flowMilliLitres   = 0;
    this->totalMilliLitres  = 0;
    this->oldTime           = millis();
    this->flowChange        = 0;

    pulseCount = 0;

    pinMode(this->pin, INPUT_PULLUP);
    attachPCINT(digitalPinToPCINT(this->pin), MP_FlowSensor::interruptHandler, FALLING);

    MP_Log::i(tag, "Ready");
    MP_Log::v(tag, "attach interrupt");
}

void MP_FlowSensor::update(unsigned long time)
{
    if (time - oldTime > 500)
    {
        MP_Log::v(tag, "update");
        disablePCINT(digitalPinToPCINT(this->pin));

        MP_Log::v(tag, pulseCount);
        unsigned long totalTimeMillis = (millis() - oldTime);
        this->flowMilliLitres = pulseCount * this->calibrationFactor;
        this->flowRate = this->flowMilliLitres * 1000.0 / totalTimeMillis;  // mL per second
        this->totalMilliLitres = this->totalMilliLitres + this->flowMilliLitres;
        this->flowChange = (flowMilliLitres > 3); // change will be detected if the flow is more than 10 mL

        MP_Log::v(tag, String("flow ML: ") + this->flowMilliLitres);
        MP_Log::v(tag, String("flow Rate: ") + this->flowRate);
        MP_Log::v(tag, String("flow totalMillis: ") + this->totalMilliLitres);

        this->oldTime = millis();
        pulseCount = 0;
        enablePCINT(digitalPinToPCINT(this->pin));
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

void MP_FlowSensor::interruptHandler()
{
    pulseCount++;
}

volatile unsigned int MP_FlowSensor::pulseCount = 0;