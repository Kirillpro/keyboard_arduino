#include <CapacitiveSensor.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>
JQ6500_Serial mp3(8,9);


CapacitiveSensor   cs_7_6 = CapacitiveSensor(7,6);  // 10M resistor between pins 7 & 6, pin 6 is sensor pin

void setup()                    
{
   //cs_7_6.set_CS_AutocaL_Millis(0xFFFFFFFF);     // turn off autocalibrate on channel 1 - just as an example
   Serial.begin(9600);
    mp3.begin(9600);
  mp3.reset();
  mp3.setVolume(15);
  mp3.setLoopMode(MP3_LOOP_NONE);

}

void loop()                    
{
    
    long total1 =  cs_7_6.capacitiveSensor(5);

    
    Serial.print(total1);             
    Serial.println("\t");

 if (total1>2000) {
 if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(1);  
  }
 }

    delay(100);                             // arbitrary delay to limit data to serial port 
}
