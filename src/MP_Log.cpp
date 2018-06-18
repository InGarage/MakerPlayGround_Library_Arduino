#include "MP_Log.h"

// Public Methods //////////////////////////////////////////////////////////////


//Debug

void MP_Log::printDebugHeader(const String &tag){
    Serial.print("DEBUG;");
    Serial.print(tag);
    Serial.print(";");
}

void MP_Log::d(const String &tag,const String &s){
    printDebugHeader(tag);
    Serial.println(s);
}

void MP_Log::d(const String &tag,const char str[]){
    printDebugHeader(tag);
    Serial.println(str);
}
void MP_Log::d(const String &tag,char c){
    printDebugHeader(tag);
    Serial.println(c);
}

void MP_Log::d(const String &tag,unsigned char b, int base){
    printDebugHeader(tag);
    Serial.println(b, base);
}

void MP_Log::d(const String &tag,int n, int base){
    printDebugHeader(tag);
    Serial.println(n, base);
}

void MP_Log::d(const String &tag,unsigned int n, int base){
    printDebugHeader(tag);
    Serial.println(n, base);
}

void MP_Log::d(const String &tag,long b, int base){
    printDebugHeader(tag);
    Serial.println(b, base);
}

void MP_Log::d(const String &tag,unsigned long n, int base){
    printDebugHeader(tag);
    Serial.println(n, base);
}

void MP_Log::d(const String &tag,double n, int digits){
    printDebugHeader(tag);
    Serial.println(n, digits);
}

void MP_Log::d(const String &tag,const Printable& x){
    printDebugHeader(tag);
    Serial.println(x);
}


//Error

void MP_Log::printErrorHeader(const String &tag){
    Serial.print("ERROR;");
    Serial.print(tag);
    Serial.print(";");
}

void MP_Log::e(const String &tag,const String &s){
    printErrorHeader(tag);
    Serial.println(s);
}

void MP_Log::e(const String &tag,const char str[]){
    printErrorHeader(tag);
    Serial.println(str);
}
void MP_Log::e(const String &tag,char c){
    printErrorHeader(tag);
    Serial.println(c);
}

void MP_Log::e(const String &tag,unsigned char b, int base){
    printErrorHeader(tag);
    Serial.println(b, base);
}

void MP_Log::e(const String &tag,int n, int base){
    printErrorHeader(tag);
    Serial.println(n, base);
}

void MP_Log::e(const String &tag,unsigned int n, int base){
    printErrorHeader(tag);
    Serial.println(n, base);
}

void MP_Log::e(const String &tag,long b, int base){
    printErrorHeader(tag);
    Serial.println(b, base);
}

void MP_Log::e(const String &tag,unsigned long n, int base){
    printErrorHeader(tag);
    Serial.println(n, base);
}

void MP_Log::e(const String &tag,double n, int digits){
    printErrorHeader(tag);
    Serial.println(n, digits);
}

void MP_Log::e(const String &tag,const Printable& x){
    printErrorHeader(tag);
    Serial.println(x);
}

//Info

void MP_Log::printInfoHeader(const String &tag){
    Serial.print("INFO;");
    Serial.print(tag);
    Serial.print(";");
}

void MP_Log::i(const String &tag,const String &s){
    printInfoHeader(tag);
    Serial.println(s);
}

void MP_Log::i(const String &tag,const char str[]){
    printInfoHeader(tag);
    Serial.println(str);
}
void MP_Log::i(const String &tag,char c){
    printInfoHeader(tag);
    Serial.println(c);

}

void MP_Log::i(const String &tag,unsigned char b, int base){
    printInfoHeader(tag);
    Serial.println(b, base);

}

void MP_Log::i(const String &tag,int n, int base){
    printInfoHeader(tag);
    Serial.println(n, base);

}

void MP_Log::i(const String &tag,unsigned int n, int base){
    printInfoHeader(tag);
    Serial.println(n, base);

}

void MP_Log::i(const String &tag,long b, int base){
    printInfoHeader(tag);
    Serial.println(b, base);

}

void MP_Log::i(const String &tag,unsigned long n, int base){
    printInfoHeader(tag);
    Serial.println(n, base);

}

void MP_Log::i(const String &tag,double n, int digits){
    printInfoHeader(tag);
    Serial.println(n, digits);

}

void MP_Log::i(const String &tag,const Printable &x){
    printInfoHeader(tag);
    Serial.println(x);

}

//Verbose

void MP_Log::printVerboseHeader(const String &tag){
    Serial.print("VERBOSE;");
    Serial.print(tag);
    Serial.print(";");
}

void MP_Log::v(const String &tag,const String &s){
    printVerboseHeader(tag);
    Serial.println(s);

}

void MP_Log::v(const String &tag,const char str[]){
    printVerboseHeader(tag);
    Serial.println(str);

}
void MP_Log::v(const String &tag,char c){
    printVerboseHeader(tag);
    Serial.println(c);

}

void MP_Log::v(const String &tag,unsigned char b, int base){
    printVerboseHeader(tag);
    Serial.println(b, base);

}

void MP_Log::v(const String &tag,int n, int base){
    printVerboseHeader(tag);
    Serial.println(n, base);

}

void MP_Log::v(const String &tag,unsigned int n, int base){
    printVerboseHeader(tag);
    Serial.println(n, base);

}

void MP_Log::v(const String &tag,long b, int base){
    printVerboseHeader(tag);
    Serial.println(b, base);

}

void MP_Log::v(const String &tag,unsigned long n, int base){
    printVerboseHeader(tag);
    Serial.println(n, base);

}

void MP_Log::v(const String &tag,double n, int digits){
    printVerboseHeader(tag);
    Serial.println(n, digits);

}

void MP_Log::v(const String &tag,const Printable& x){
    printVerboseHeader(tag);
    Serial.println(x);

}

// Warning

void MP_Log::printWarningHeader(const String &tag){
    Serial.print("WARNING;");
    Serial.print(tag);
    Serial.print(";");
}

void MP_Log::w(const String &tag,const String &s){
    printWarningHeader(tag);
    Serial.println(s);

}

void MP_Log::w(const String &tag,const char str[]){
    printWarningHeader(tag);
    Serial.println(str);

}
void MP_Log::w(const String &tag,char c){
    printWarningHeader(tag);
    Serial.println(c);

}

void MP_Log::w(const String &tag,unsigned char b, int base){
    printWarningHeader(tag);
    Serial.println(b, base);

}

void MP_Log::w(const String &tag,int n, int base){
    printWarningHeader(tag);
    Serial.println(n, base);

}

void MP_Log::w(const String &tag,unsigned int n, int base){
    printWarningHeader(tag);
    Serial.println(n, base);

}

void MP_Log::w(const String &tag,long b, int base){
    printWarningHeader(tag);
    Serial.println(b, base);

}

void MP_Log::w(const String &tag,unsigned long n, int base){
    printWarningHeader(tag);
    Serial.println(n, base);

}

void MP_Log::w(const String &tag,double n, int digits){
    printWarningHeader(tag);
    Serial.println(n, digits);

}

void MP_Log::w(const String &tag,const Printable& x){
    printWarningHeader(tag);
    Serial.println(x);

}