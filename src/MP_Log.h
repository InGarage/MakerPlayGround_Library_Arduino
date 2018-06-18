#ifndef MP_Log_H
#define MP_Log_H

#include <Arduino.h>

#define DEC 10
#define HEX 16
#define OCT 8
#ifdef BIN // Prevent warnings if BIN is previously defined in "iotnx4.h" or similar
#undef BIN
#endif
#define BIN 2

namespace MP_Log
{
    void printDebugHeader(const String &);
    void d(const String &, const String &);
    void d(const String &,const String &);
    void d(const String &,const char[]);
    void d(const String &,char);
    void d(const String &,unsigned char, int = DEC);
    void d(const String &,int, int = DEC);
    void d(const String &,unsigned int, int = DEC);
    void d(const String &,long, int = DEC);
    void d(const String &,unsigned long, int = DEC);
    void d(const String &,double, int = 2);
    void d(const String &,const Printable&);

    void printErrorHeader(const String &);
    void e(const String &, const String &);
    void e(const String &,const String &);
    void e(const String &,const char[]);
    void e(const String &,char);
    void e(const String &,unsigned char, int = DEC);
    void e(const String &,int, int = DEC);
    void e(const String &,unsigned int, int = DEC);
    void e(const String &,long, int = DEC);
    void e(const String &,unsigned long, int = DEC);
    void e(const String &,double, int = 2);
    void e(const String &,const Printable&);

    void printWarningHeader(const String &);
    void w(const String &, const String &);
    void w(const String &,const String &);
    void w(const String &,const char[]);
    void w(const String &,char);
    void w(const String &,unsigned char, int = DEC);
    void w(const String &,int, int = DEC);
    void w(const String &,unsigned int, int = DEC);
    void w(const String &,long, int = DEC);
    void w(const String &,unsigned long, int = DEC);
    void w(const String &,double, int = 2);
    void w(const String &,const Printable&);

    void printInfoHeader(const String &);
    void i(const String &, const String &);
    void i(const String &,const String &);
    void i(const String &,const char[]);
    void i(const String &,char);
    void i(const String &,unsigned char, int = DEC);
    void i(const String &,int, int = DEC);
    void i(const String &,unsigned int, int = DEC);
    void i(const String &,long, int = DEC);
    void i(const String &,unsigned long, int = DEC);
    void i(const String &,double, int = 2);
    void i(const String &,const Printable &);

    void printVerboseHeader(const String &);
    void v(const String &,const String &);
    void v(const String &,const String &);
    void v(const String &,const char[]);
    void v(const String &,char);
    void v(const String &,unsigned char, int = DEC);
    void v(const String &,int, int = DEC);
    void v(const String &,unsigned int, int = DEC);
    void v(const String &,long, int = DEC);
    void v(const String &,unsigned long, int = DEC);
    void v(const String &,double, int = 2);
    void v(const String &,const Printable&);

};

#endif