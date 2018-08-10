#include <Arduino.h>
#include <SoftwareSerial.h>
#include <JQ6500_Serial.h>

#define SCL_PIN 2
#define SDO_PIN 3

/* Used to store the key state */
byte Key;
JQ6500_Serial mp3(8,9);
void setup()
{
 /* Initialize the serial interface */
 Serial.begin(9600);
 /* Configure the clock and data pins */
 pinMode(SCL_PIN, OUTPUT);  
 pinMode(SDO_PIN, INPUT); 
 mp3.begin(9600);
  mp3.reset();
  mp3.setVolume(15);
  mp3.setLoopMode(MP3_LOOP_NONE);
}
/* Main program */
void loop()
{
 /* Read the current state of the keypad */
 Key = Read_Keypad();
 switch (Key){
  case 1:
  Serial.println('A');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(1);  
  }
  break;
  case 2:
  Serial.println('B');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(2);  
  }
  
  break;
  case 3:
  Serial.println('C');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(099);  
  }
  
  break;
  case 4:
  Serial.println('D');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(100);  
  }
  
  break;
  case 5:
  Serial. println('E');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(04);  
  }
  
  break;
  case 6:
  Serial.println('G');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(101);  
  }
  
  break;
  case 7:
  Serial.println('H');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(05);  
  }
  
  break;
  case 8:
  Serial.println('I');
  if(mp3.getStatus() != MP3_STATUS_PLAYING)
  {
    mp3.playFileByIndexNumber(06);  
  }
  break;
 }
 
 /* If a key has been pressed output it to the serial port */ 
 /* Wait a little before reading again 
  so not to flood the serial port*/
 delay(300);
}
/* Read the state of the keypad */
byte Read_Keypad(void)
{
 byte Count;
 byte Key_State = 0;
 /* Pulse the clock pin 16 times (one for each key of the keypad) 
    and read the state of the data pin on each pulse */
 for(Count = 1; Count <= 8; Count++)
 {
   digitalWrite(SCL_PIN, LOW); 
  /* If the data pin is low (active low mode) then store the 
      current key number */
   if (!digitalRead(SDO_PIN))
     Key_State = Count; 
     digitalWrite(SCL_PIN, HIGH);
 }  
 return Key_State; 
}
