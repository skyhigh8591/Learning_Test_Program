
#include "pitches.h"

int buzzerPin = 10;
const int beatLength = 500;
int number,stopTone,count;

int basicTone[]={0,NOTE_C4,NOTE_D4,NOTE_E4,NOTE_F4,NOTE_G4,NOTE_A4,NOTE_B4,NOTE_C5,NOTE_D5,NOTE_E5,NOTE_F5,NOTE_G5,NOTE_A5,NOTE_B5};


void setup() {
  Serial.begin(9600);
  pinMode(buzzerPin,OUTPUT);

  number = basicTone[1];
  Serial.print("baseic tone number =");
  Serial.println(number);
  stopTone = beatLength * 1.3;
  tone(buzzerPin,number,beatLength);
  delay(stopTone);

  number = basicTone[2];
  Serial.print("baseic tone number =");
  Serial.println(number);
  tone(buzzerPin,number,beatLength);
  delay(stopTone);
   


  count = sizeof( basicTone)/sizeof( basicTone[0]);

  Serial.print("basicTone[0] = ");
  Serial.println(sizeof( basicTone[0]));
  Serial.print("count =");
  Serial.println(count);

  for(int i = 0; i<count ; i++)
  {
    number = basicTone[i];
    Serial.print("baseic tone number =");
    Serial.println(number);
    tone(buzzerPin,number,beatLength);
    delay(stopTone);
 
  }



}

void loop() {
  char data;
  int index;
  if(Serial.available()>0){
    data = Serial.read();
    Serial.print("Serial.read = ");
    Serial.println(data);
  }

  index = data- '0';
  if(index >=0 && index < 10)
  {
    Serial.print("index = ");
    Serial.println(index);
    number = basicTone[index];
    Serial.print("basic tone number =");
    Serial.println(number);
    tone(buzzerPin,number,beatLength);
    delay(stopTone);
    
  }

   index = data - 'A';

   if(index >=0 && index < 5)
  {
  index = index +10;
  
    Serial.print("index = ");
    Serial.println(index);
    number = basicTone[index];
    Serial.print("basic tone number =");
    Serial.println(number);
    tone(buzzerPin,number,beatLength);
    delay(stopTone);
  }

     index = data - 'a';

   if(index >=0 && index < 5)
  {
  index = index +10;
  
    Serial.print("index = ");
    Serial.println(index);
    number = basicTone[index];
    Serial.print("basic tone number =");
    Serial.println(number);
    tone(buzzerPin,number,beatLength);
    delay(stopTone);
  }
  

}
