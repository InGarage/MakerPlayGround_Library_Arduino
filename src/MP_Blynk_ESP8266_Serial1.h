#ifndef MP_Blynk_ESP8266_SERIAL1_H
#define MP_Blynk_ESP8266_SERIAL1_H

#include <Arduino.h>
#include <ESP8266_Lib.h>

class MP_Blynk_ESP8266_Serial1 
{
public:
    MP_Blynk_ESP8266_Serial1(char auth[], char ssid[], char pass[]);

    void init();
    void update(unsigned long time);

    int readVirtualPin(uint8_t pin);   // pin = 0-7
    void writeVirtualPin(char pin[], int value);   // pin = 0-7

    // high level function use by maker playground
    bool checkVirtualPinValue(char pin[], int value);
    int getVirtualPin0();
    int getVirtualPin1();
    int getVirtualPin2();
    int getVirtualPin3();
    int getVirtualPin4();
    int getVirtualPin5();
    int getVirtualPin6();
    int getVirtualPin7();

    // TODO: find alternate implementation as these may be dangerous
    static int value[8];
    static uint8_t valueChanged; // flag indicated that the data has changed

private:
    ESP8266 wifi;
    char* auth;
    char* ssid;
    char* pass;

    unsigned long lastSendMillis;   // time of the last time we send some data to blynk server
};

#endif