#define BLYNK_PRINT Serial
#define ESP8266_BAUD 115200
#define SEND_GAP 100    // in ms (100 mean we send 10 times / sec)
#define PING_GAP 30000  // in ms (ping every 30 secs)

#include "MP_Blynk_ESP8266_Serial1.h"
#include <BlynkSimpleShieldEsp8266.h>

double MP_Blynk_ESP8266_Serial1::value[8];
uint8_t MP_Blynk_ESP8266_Serial1::valueChanged;

MP_Blynk_ESP8266_Serial1::MP_Blynk_ESP8266_Serial1(char* auth, char* ssid, char* pass)
    : wifi(&Serial1)
    , auth(auth)
    , ssid(ssid)
    , pass(pass)
    , lastSendMillis(0)
    , lastPingMillis(0)
{
    for (uint8_t i=0; i<8; i++)
    {
        MP_Blynk_ESP8266_Serial1::value[i] = 0;
    }
}

void MP_Blynk_ESP8266_Serial1::ledOn() {
    // rev 0 board
    Serial1.println(F("AT+CIOWRITE=0,0"));
    recvString("OK", "ERROR", 1000);
    // rev1 board
    Serial1.println(F("AT+SYSGPIOWRITE=0,0"));
    recvString("OK", "ERROR", 1000);
}

void MP_Blynk_ESP8266_Serial1::ledOff() {
    // rev 0 board
    Serial1.println(F("AT+CIOWRITE=0,1"));
    recvString("OK", "ERROR", 1000);
    // rev1 board
    Serial1.println(F("AT+SYSGPIOWRITE=0,1"));
    recvString("OK", "ERROR", 1000);
}

String MP_Blynk_ESP8266_Serial1::recvString(String target1, String target2, uint32_t timeout)
{
    String data;
    char a;
    unsigned long start = millis();
    while (millis() - start < timeout) {
        while(Serial1.available() > 0) {
            a = Serial1.read();
            if(a == '\0') continue;
            data += a;
            if (data.indexOf(target1) != -1) {
                return data;
            } else if (data.indexOf(target2) != -1) {
                return data;
            } /*else if (checkIPD(data)) {
                data = "";
            }*/
        }
    }
    return data;
}

void MP_Blynk_ESP8266_Serial1::init() 
{
    Serial1.begin(115200);
    delay(10);
    // setup gpio (rev 1 board only)
    Serial1.println(F("AT+SYSGPIODIR=0,1"));
    recvString("OK", "ERROR", 1000);
    // connect to wifi and blynk server
    wifiInit();
}

void MP_Blynk_ESP8266_Serial1::wifiInit()
{
    // initial wifi
    ledOff();
    Blynk.config(this->wifi, this->auth, BLYNK_DEFAULT_DOMAIN, BLYNK_DEFAULT_PORT);
    while (!Blynk.connectWiFi(this->ssid, this->pass)) {
        delay(1);
    }

    // connected
    ledOn();

    // test for Blynk connection
    while(Blynk.connect() != true) {
        if (!testConnection()) {
            // no internet
            ledOff();
            while (!Blynk.connectWiFi(this->ssid, this->pass)) {
                delay(1);
            }
            ledOn();
            // reconnected success
        }
        else {
            // having internet but can't connect to blink server
        }
        delay(PING_GAP);
    }
}

bool MP_Blynk_ESP8266_Serial1::testConnection()
{
    // test connection
    Serial1.println(F("AT+PING=\"4.2.2.2\""));
    String data = recvString("OK", "ERROR", 5000);
    return (data.indexOf("OK") != -1);
}

void MP_Blynk_ESP8266_Serial1::update(unsigned long time) 
{
    Blynk.run();
    // push value waited to be push to blynk server
    if (time - lastSendMillis > SEND_GAP) 
    {
        for (uint8_t i=0; i<8; i++)
        {
            if (MP_Blynk_ESP8266_Serial1::valueChanged & (1 << i)) 
            {
                Blynk.virtualWrite(i, MP_Blynk_ESP8266_Serial1::value[i]);
                MP_Blynk_ESP8266_Serial1::valueChanged &= ~(1 << i);
            }
        }
        lastSendMillis = time;
    }
    // ping to check network connection
    if (time - lastPingMillis > PING_GAP)
    {
        if (!testConnection()) {
            wifiInit();
        }
        lastPingMillis = time;
    }
}

int MP_Blynk_ESP8266_Serial1::readVirtualPin(uint8_t pin) 
{
    return MP_Blynk_ESP8266_Serial1::value[pin];
}

void MP_Blynk_ESP8266_Serial1::writeVirtualPin(char pin[], double value)
{
    MP_Log::i(tag,String("Send: ") + MP_Blynk_ESP8266_Serial1::value[pin[0] - '0']);
    MP_Blynk_ESP8266_Serial1::value[pin[0] - '0'] = value;
    MP_Blynk_ESP8266_Serial1::valueChanged |= (1 << (pin[0] - '0'));
}

bool MP_Blynk_ESP8266_Serial1::checkVirtualPinValue(char pin[], int value)
{
    MP_Log::i(tag,String("Receive: ") + MP_Blynk_ESP8266_Serial1::value[pin[0] - '0']);
    return MP_Blynk_ESP8266_Serial1::value[pin[0] - '0'] == value;
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin0()
{
    return this->readVirtualPin(0);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin1()
{
    return this->readVirtualPin(1);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin2()
{
    return this->readVirtualPin(2);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin3()
{
    return this->readVirtualPin(3);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin4()
{
    return this->readVirtualPin(4);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin5()
{
    return this->readVirtualPin(5);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin6()
{
    return this->readVirtualPin(6);
}

int MP_Blynk_ESP8266_Serial1::getVirtualPin7()
{
    return this->readVirtualPin(7);
}

BLYNK_READ(V0) 
{
    Blynk.virtualWrite(0, MP_Blynk_ESP8266_Serial1::value[0]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(0);
}

BLYNK_READ(V1) 
{
    Blynk.virtualWrite(1, MP_Blynk_ESP8266_Serial1::value[1]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(1);
}

BLYNK_READ(V2) 
{
    Blynk.virtualWrite(2, MP_Blynk_ESP8266_Serial1::value[2]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(2);
}

BLYNK_READ(V3) 
{
    Blynk.virtualWrite(3, MP_Blynk_ESP8266_Serial1::value[3]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(3);
}

BLYNK_READ(V4) 
{
    Blynk.virtualWrite(4, MP_Blynk_ESP8266_Serial1::value[4]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(4);
}

BLYNK_READ(V5) 
{
    Blynk.virtualWrite(5, MP_Blynk_ESP8266_Serial1::value[5]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(5);
}

BLYNK_READ(V6) 
{
    Blynk.virtualWrite(6, MP_Blynk_ESP8266_Serial1::value[6]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(6);
}

BLYNK_READ(V7) 
{
    Blynk.virtualWrite(7, MP_Blynk_ESP8266_Serial1::value[7]);
    MP_Blynk_ESP8266_Serial1::valueChanged &= ~_BV(7);
}

BLYNK_WRITE(V0) 
{
    MP_Blynk_ESP8266_Serial1::value[0] = param.asInt();
}

BLYNK_WRITE(V1) 
{
    MP_Blynk_ESP8266_Serial1::value[1] = param.asInt();
}

BLYNK_WRITE(V2) 
{
    MP_Blynk_ESP8266_Serial1::value[2] = param.asInt();
}

BLYNK_WRITE(V3) 
{
    MP_Blynk_ESP8266_Serial1::value[3] = param.asInt();
}

BLYNK_WRITE(V4) 
{
    MP_Blynk_ESP8266_Serial1::value[4] = param.asInt();
}

BLYNK_WRITE(V5) 
{
    MP_Blynk_ESP8266_Serial1::value[5] = param.asInt();
}

BLYNK_WRITE(V6) 
{
    MP_Blynk_ESP8266_Serial1::value[6] = param.asInt();
}

BLYNK_WRITE(V7) 
{
    MP_Blynk_ESP8266_Serial1::value[7] = param.asInt();
}