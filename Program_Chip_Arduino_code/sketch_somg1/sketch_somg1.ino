#include "pitches.h"

int buzzerPin = 10;
const int beatLength = 500;
int basicTone[]={0,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};

byte noteNumber_basic[]={0,1,2,3,4,5,6,7,1+7,2+7,3+7,4+7,5+7,6+7,7+7,0xff};

byte note_littleStar[]={1,1,5,5,6,6,5,4,4,3,3,2,2,1,0xff};
int beat_littleStar[]= {1,1,1,1,1,1,2,1,1,1,1,1,1,2};

int index,songNumber,beatNumber;

void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);
  index=0;

  while(1){
  songNumber = noteNumber_basic[index];
  if(songNumber == 0xff)
      break;
  tone(buzzerPin,basicTone[songNumber],beatLength);
  delay(beatLength * 1.3);
  index++;
  }
}

void loop() {
  play_littleStar();
}

void play_littleStar()
{
  index = 0;
  while(1)
  {
    songNumber = note_littleStar[index];
    beatNumber = beat_littleStar[index] * beatLength;

    if(songNumber == 0xff)
      break;
  tone(buzzerPin,basicTone[songNumber],beatNumber);
  delay(beatLength * 1.3);
  index++;
  }
}

