#define BLYNK_PRINT Serial
#define ESP8266_BAUD 9600
#define SEND_GAP 100    // in ms (100 mean we send 10 times / sec)

#include "MP_Blynk_ESP8266.h"
#include <BlynkSimpleShieldEsp8266.h>

int MP_Blynk_ESP8266::value[8];
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
                MP_Blynk_ESP8266::valueChanged &= (1 << i);
            }
        }
    }
}

int MP_Blynk_ESP8266::readVirtualPin(uint8_t pin) 
{
    return MP_Blynk_ESP8266::value[pin];
}

void MP_Blynk_ESP8266::writeVirtualPin(uint8_t pin, int value)
{
    MP_Blynk_ESP8266::value[pin] = value;
    MP_Blynk_ESP8266::valueChanged |= (1 << pin);
}

bool MP_Blynk_ESP8266::checkVirtualPinValue(uint8_t pin, int value)
{
    return MP_Blynk_ESP8266::value[pin] == value;
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

BLYNK_WRITE(V0) 
{
    MP_Blynk_ESP8266::value[0] = param.asInt();
}

BLYNK_WRITE(V1) 
{
    MP_Blynk_ESP8266::value[1] = param.asInt();
}