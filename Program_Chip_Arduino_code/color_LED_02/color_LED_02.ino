
int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int i,x,z;
byte value,bitValue,temp,randNum;

void setup() { 

    Serial.begin(9600);
    value = B00001000;
    Serial.print("value= ");
    Serial.println(value,BIN);

    bitValue = value >> 1;

    Serial.print("bitValue= ");
    Serial.println(bitValue,BIN);

    bitValue = value >> 2;

    Serial.print("bitValue= ");
    Serial.println(bitValue,BIN);

    bitValue = value >> 3;

    Serial.print("bitValue= ");
    Serial.println(bitValue,BIN);

    value = B11111111;
    Serial.print("value= ");
    Serial.println(value,BIN);

    temp = B00001100;
    value = value & temp;
    Serial.print("value= ");
    Serial.println(value,BIN);

    value = value >> 2;
    Serial.print("value= ");
    Serial.println(value,BIN);
    
    set();

    for(i = 0 ; i < 8 ; i++)
    {
      value = i;
      bitValue = value & 0x01;
      digitalWrite(10, bitValue);
      bitValue = (value >> 1) & 0x01; 
      digitalWrite(11, bitValue);
      bitValue = (value >> 2) & 0x01;
      digitalWrite(12, bitValue);
      delay(1000);
    }                                                                          
}
void loop() {

}

void set(){
    pinMode(10, OUTPUT);
    pinMode(11, OUTPUT);
    pinMode(12, OUTPUT);

    for(int i = 0 ; i < 8 ; i ++)
    {
      value = i;
      bitValue = value & 0x01;
      digitalWrite(10, bitValue);
      bitValue = (value >> 1) & 0x01; 
      digitalWrite(11, bitValue);
      bitValue = (value >> 2) & 0x01;
      digitalWrite(12, bitValue);
      delay(1000);    
    }
    
  attachInterrupt(0,colorChange,RISING);
  value = analogRead(A0);
  Serial.println("A0 value= ");
  Serial.println(value);

  randomSeed(value);
  
    
  
}

void colorChange()
{
   Serial.println("key was pressed");
   randNum = random(0,100);
   Serial.println(randNum);  
   value = randNum % 8;
   Serial.println(value);  
   
      bitValue = value & 0x01;
      digitalWrite(10, bitValue);
      bitValue = (value >> 1) & 0x01; 
      digitalWrite(11, bitValue);
      bitValue = (value >> 2) & 0x01;
      digitalWrite(12, bitValue);
      
   delay(3000);
}


