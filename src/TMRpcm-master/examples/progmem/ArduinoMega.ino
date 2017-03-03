
#include <SD.h>                      // need to include the SD library
#define SD_ChipSelectPin 53  //using digital pin 4 on arduino nano 328
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch
 
void setup(){

 
  tmrpcm.speakerPin = 11; //11 on Mega, 9 on Uno, Nano, etc
 
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
  return;   // don't do anything more if not
  }
 tmrpcm.volume(1);
 
}
 
void loop(){  

     
      tmrpcm.play("6.wav");
      delay(1000);
      tmrpcm.play("4.wav");
     delay(3000);
      tmrpcm.play("5.wav");
     delay(4000);
      tmrpcm.play("3.wav");
      delay(2000);
      tmrpcm.play("88.wav");
      delay(50000);
    }
  

