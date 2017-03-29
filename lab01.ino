#include "SevSeg.h"
 int Hour=0,Min=0,t=0;
SevSeg sevseg;
void setup() {
byte numDigits = 4;
byte digitPins[] = {5,4,3,2};
byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
Serial.begin(9600);
}
void loop()
{
 
  sevseg.setNumber(Hour * 100 + Min, 4);
  for(t=0;t<=30000;t++)
  {
    sevseg.refreshDisplay();
  }
Min = Min + 1;
if(Min == 60)
{ 
Min = 0;
if (Hour == 23) 
Hour=0;
else 
Hour++;
}
}
