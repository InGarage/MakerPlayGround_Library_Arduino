#ifndef MP_Blynk_ESP8266_H
#define MP_Blynk_ESP8266_H

#include <Arduino.h>
#include <SoftwareSerial.h>
#include <ESP8266_Lib.h>

class MP_Blynk_ESP8266 
{
public:
    MP_Blynk_ESP8266(uint8_t rx, uint8_t tx, char auth[], char ssid[], char pass[]);

    void init();
    void update(unsigned long time);

    int readVirtualPin(uint8_t pin);   // pin = 0-7
    void writeVirtualPin(uint8_t pin, int value);   // pin = 0-7

    // high level function use by maker playground
    bool checkVirtualPinValue(uint8_t pin, int value);

    // TODO: find alternate implementation as these may be dangerous
    static int value[8];
    static uint8_t valueChanged; // flag indicated that the data has changed

private:
    SoftwareSerial espSerial;
    ESP8266 wifi;
    char* auth;
    char* ssid;
    char* pass;

    unsigned long lastSendMillis;   // time of the last time we send some data to blynk server
};

#endif