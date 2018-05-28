#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600
#define SEND_GAP 100    // in ms (100 mean we send 10 times / sec)

#include "MP_Blynk_ESP8266.h"
#include <BlynkSimpleShieldEsp8266.h>

double MP_Blynk_ESP8266::value[8];
uint8_t MP_Blynk_ESP8266::valueChanged;

MP_Blynk_ESP8266::MP_Blynk_ESP8266(uint8_t rx, uint8_t tx, char* auth, char* ssid, char* pass)
    : espSerial(SoftwareSerial(rx, tx))
    , wifi(&espSerial)
    , auth(auth)
    , ssid(ssid)
    , pass(pass)
    , lastSendMillis(0)
{
    for (uint8_t i=0; i<8; i++)
    {
        MP_Blynk_ESP8266::value[i] = 0;
    }
}

void MP_Blynk_ESP8266::init() 
{
    this->espSerial.begin(ESP8266_BAUD);
    delay(10);
    Blynk.begin(this->auth, this->wifi, this->ssid, this->pass);
}

void MP_Blynk_ESP8266::update(unsigned long time) 
{
    Blynk.run();
    // push value waited to be push to blynk server
    if (time - lastSendMillis > SEND_GAP) 
    {
        for (uint8_t i=0; i<8; i++)
        {
            if (MP_Blynk_ESP8266::valueChanged & (1 << i)) 
            {
                Blynk.virtualWrite(i, MP_Blynk_ESP8266::value[i]);
                MP_Blynk_ESP8266::valueChanged &= ~(1 << i);
            }
        }
        lastSendMillis = time;
    }
}

int MP_Blynk_ESP8266::readVirtualPin(uint8_t pin) 
{
    return MP_Blynk_ESP8266::value[pin];
}

void MP_Blynk_ESP8266::writeVirtualPin(char pin[], double value)
{
    MP_Blynk_ESP8266::value[pin[0] - '0'] = value;
    MP_Blynk_ESP8266::valueChanged |= (1 << (pin[0] - '0'));
}

bool MP_Blynk_ESP8266::checkVirtualPinValue(char pin[], int value)
{
    return MP_Blynk_ESP8266::value[pin[0] - '0'] == value;
}

int MP_Blynk_ESP8266::getVirtualPin0()
{
    return this->readVirtualPin(0);
}

int MP_Blynk_ESP8266::getVirtualPin1()
{
    return this->readVirtualPin(1);
}

int MP_Blynk_ESP8266::getVirtualPin2()
{
    return this->readVirtualPin(2);
}

int MP_Blynk_ESP8266::getVirtualPin3()
{
    return this->readVirtualPin(3);
}

int MP_Blynk_ESP8266::getVirtualPin4()
{
    return this->readVirtualPin(4);
}

int MP_Blynk_ESP8266::getVirtualPin5()
{
    return this->readVirtualPin(5);
}

int MP_Blynk_ESP8266::getVirtualPin6()
{
    return this->readVirtualPin(6);
}

int MP_Blynk_ESP8266::getVirtualPin7()
{
    return this->readVirtualPin(7);
}

BLYNK_READ(V0) 
{
    Blynk.virtualWrite(0, MP_Blynk_ESP8266::value[0]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(0);
}

BLYNK_READ(V1) 
{
    Blynk.virtualWrite(1, MP_Blynk_ESP8266::value[1]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(1);
}

BLYNK_READ(V2) 
{
    Blynk.virtualWrite(2, MP_Blynk_ESP8266::value[2]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(2);
}

BLYNK_READ(V3) 
{
    Blynk.virtualWrite(3, MP_Blynk_ESP8266::value[3]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(3);
}

BLYNK_READ(V4) 
{
    Blynk.virtualWrite(4, MP_Blynk_ESP8266::value[4]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(4);
}

BLYNK_READ(V5) 
{
    Blynk.virtualWrite(5, MP_Blynk_ESP8266::value[5]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(5);
}

BLYNK_READ(V6) 
{
    Blynk.virtualWrite(6, MP_Blynk_ESP8266::value[6]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(6);
}

BLYNK_READ(V7) 
{
    Blynk.virtualWrite(7, MP_Blynk_ESP8266::value[7]);
    MP_Blynk_ESP8266::valueChanged &= ~_BV(7);
}

BLYNK_WRITE(V0) 
{
    MP_Blynk_ESP8266::value[0] = param.asInt();
}

BLYNK_WRITE(V1) 
{
    MP_Blynk_ESP8266::value[1] = param.asInt();
}

BLYNK_WRITE(V2) 
{
    MP_Blynk_ESP8266::value[2] = param.asInt();
}

BLYNK_WRITE(V3) 
{
    MP_Blynk_ESP8266::value[3] = param.asInt();
}

BLYNK_WRITE(V4) 
{
    MP_Blynk_ESP8266::value[4] = param.asInt();
}

BLYNK_WRITE(V5) 
{
    MP_Blynk_ESP8266::value[5] = param.asInt();
}

BLYNK_WRITE(V6) 
{
    MP_Blynk_ESP8266::value[6] = param.asInt();
}

BLYNK_WRITE(V7) 
{
    MP_Blynk_ESP8266::value[7] = param.asInt();
}