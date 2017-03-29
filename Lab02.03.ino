#include "SevSeg.h"

SevSeg sevseg;
int Hour = 0,Min = 0,t = 0;
int Pin10;
int Pin11;
int Step;

void setup() 
{
  Serial.begin(9600);
  byte numDigits = 4;
  byte digitPins[] = {5,4,3,2};
  byte segmentPins[] = {6, 7, 8, 9, 10, 11, 12, 13};
  sevseg.begin(COMMON_CATHODE, numDigits, digitPins,segmentPins);
  pinMode(A0,INPUT_PULLUP);
  pinMode(A1,INPUT_PULLUP);
  Step = 1;
}

void loop() 
{
  sevseg.setNumber(Hour * 100 + Min, 4);
  for(t=0;t<30000;t++)
  {
    sevseg.refreshDisplay();
  }
  Min = Min + Step;
  if(Min==60)
  {
    Min=0;
    if(Hour==23)
    {
      Hour=0;
    }
    else
    {
      Hour++;
    }
  }
  if(Min==-1)
  {
    Min = 59;
    if(Hour==0)
    {
      Hour=23;
    }
    else
    {
      Hour--;
    }
  }
  Pin10 = digitalRead(A0);
  if(Pin10 == 0)
  {
    Min = 0;
    Hour = 0;
  }
  Pin11 = digitalRead(A1);
  if(Pin11 == 0)
  {
    Step = -1;
  }
  else
  {
    Step = 1;
  }
}
