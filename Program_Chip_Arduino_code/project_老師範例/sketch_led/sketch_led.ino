
int ledPin[]={3,3,4,5,6,7,8,9};
int i;
int key1 = 13;
int value, buttonState;

void setup() {
    Serial.begin(9600);
    
    for(i=0; i<8 ; i++)
    {
      pinMode(ledPin[i],OUTPUT);
    }
    
 for(int j = 0; j< 3; j++)
      ledAllOn();
//-------------------------------------------------

    ledOneOn();
 
//-------------------------------------------------------------------
 
  for(int j = 0; j< 3; j++)
    ledOddEven();

    attachInterrupt(0, valueChange, RISING);
    pinMode(key1, INPUT);
    value = 0;
    Serial.print("value = ");
    Serial.println(value);
    

}

void loop() {
//    buttonState = digitalRead(key1);
//    if(buttonState == LOW)
//    {
//      value++;
//      if( value >= 3)
//          value = 0;
//       Serial.print("value = ");
//       Serial.println(value);   
//    }

    switch(value)
    {
      case 0:
        ledAllOn();
        break;

      case 1:
         ledOneOn();
         break;

       case 2:
         ledOddEven();
         break;   
    } // end of switch
  
} // end of loop

void valueChange()
{
       value++;
      if( value >= 3){
          value = 0;
      }
       Serial.print("value = ");
       Serial.println(value);  
       delay(3000); 
}

void ledAllOn()
{
 for(i=0 ; i< 8; i++)
  {
    digitalWrite( ledPin[i], HIGH);
  }

   delay(1000);

   for(i=0 ; i< 8; i++)
  {
    digitalWrite( ledPin[i], LOW);
  }

   delay(1000);

}

void ledOneOn()
{
    for(i=0 ; i< 8; i++)
  {
    digitalWrite( ledPin[i], HIGH);
     delay(300);
  }

  for(i=0 ; i< 8; i++)
  {
    digitalWrite( ledPin[i], LOW);
    delay(300);
  }

}

void ledOddEven()
{
 for(i=0; i<8; i++)
  {
    if( (i%2) == 0)
      digitalWrite(ledPin[i],HIGH);
  }  
  delay(1000);
  
  for(i=0; i<8; i++)
  {
    if(i%2 == 0)
      digitalWrite(ledPin[i],LOW);   
  }

  for(i=0; i<8; i++)
  {
    if( (i%2) == 1)
      digitalWrite(ledPin[i],HIGH);
  }
  delay(1000);
   
  for(i=0; i<8; i++)
  {
    if( (i%2)==1)
      digitalWrite(ledPin[i],LOW);
  }

//  delay(1000);
  
}

