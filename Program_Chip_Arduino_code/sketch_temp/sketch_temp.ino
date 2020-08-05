#include<Wire.h>
#include "LiquidCrystal_I2C.h"

LiquidCrystal_I2C lcd(0x3f,16,2);
char data[]=" ";

void setup() {
  Serial.begin(9600);
  pinMode(A1,INPUT);
  pinMode(11,OUTPUT);

  digitalWrite(11,LOW);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Hello word");
  lcd.setCursor(0,1);
  lcd.print("LCD display");

}

void loop() {
  int value;
  float tempValue;

  value = analogRead(A1);
  Serial.print("value = ");
  Serial.println(value);
  tempValue = ((value*4.9) - 500)/10;
  Serial.print("temp = ");
  Serial.println(tempValue);



  icd.clear();
  lcd.setCursor(0,0);
  lcd.print("temp = ");
  dtostrf(tempValue,2,2,data);
  lcd.print(data);
  delay(5000);


  
  
}
