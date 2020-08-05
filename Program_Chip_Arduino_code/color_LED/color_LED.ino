
int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int i,x,z;
byte value,bitValue;

void setup() { 
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
  
}

void White() {
   digitalWrite(10, LOW);
   digitalWrite(11, LOW);
   digitalWrite(12, LOW);
   delay(1000);
}

void Lightblue() {
  digitalWrite(10, HIGH);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  delay(1000);
}

void blue() {
  digitalWrite(10, HIGH);
  digitalWrite(11, HIGH);
  digitalWrite(12, LOW);
  delay(1000);
}

void green(){
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, HIGH);
  delay(1000);  
}
void red(){
   digitalWrite(10, LOW);
   digitalWrite(11, HIGH);
   digitalWrite(12, HIGH);
   delay(1000); 
}

