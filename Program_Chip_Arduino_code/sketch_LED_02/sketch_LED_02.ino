
int ledPin[]={3,3,4,5,6,7,8,9,10,11};
int i;
int key1 = 13;
int value,buttonState;

void setup() {
  
  Serial.begin(9600);
  for(i = 0 ; i<12;i++)
  {
    pinMode(ledPin[i],OUTPUT);
  }
  for(int j = 0 ; j<3; j++)
  ledAIIOn();
//.........................
  ledOneOn();
//...........................
   for(int j = 0 ; j<3; j++)
  {
    ledOneEven();
  }
  attachInterrupt(0,valueChange,RISING); 
  
  pinMode(key1,INPUT);
  value = 0;
  Serial.print("value =");
  Serial.println(value); 
}

void loop() {

  buttonState = digitalRead(key1);
  
  if(buttonState == LOW)
  {
    value ++;
    if(value >= 3)
    value = 0;
    Serial.print("value =");
    Serial.println(value);
  }
  switch(value)
  {
    case 0:
    ledAIIOn();
    break;

    case 1:
    ledOneOn();
    break;

    case 2:
    ledOneEven();
    break;
    
    
  }
  
}

void valueChange()
{
  value++;
  if(value>=3){
    value = 0;
  }
  Serial.print("value =");
  Serial.println(value);
  delay(2000);
}

void OUTPUTLED() {


  for (i = 0 ; i < 12 ; i++)
  {
    pinMode(ledPin[i], OUTPUT);
  }
}



void OPCLOSE() {
  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  digitalWrite(6, HIGH);
  digitalWrite(7, LOW);
  digitalWrite(8, HIGH);
  digitalWrite(9, LOW);

  delay(1000);

  digitalWrite(2, LOW);
  digitalWrite(3, HIGH);
  digitalWrite(4, LOW);
  digitalWrite(5, HIGH);
  digitalWrite(6, LOW);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  digitalWrite(9, HIGH);
  delay(1000);
}

void ledAIIOn() {

  for (i = 0 ; i < 12 ; i++)
  {
    digitalWrite(ledPin[i], HIGH);
  }

  delay(100);

  for (i = 0 ; i < 12 ; i++)
  {
    digitalWrite(ledPin[i], LOW);
  }
  delay(100);
}

void ledOneOn() {
  for (i = 0 ; i < 12 ; i++)
  {
    digitalWrite(ledPin[i], HIGH);
    delay(100);
  }


  for (i = 0 ; i < 12 ; i++)
  {
    digitalWrite(ledPin[i], LOW);
    delay(100);
  }
}

void ledOneEven() {
  for (i = 0; i < 12; i++)
  {
    if ((i % 2) == 0) {
      digitalWrite(ledPin[i], HIGH);
    }
    if (i % 2) {
      digitalWrite(ledPin[i], LOW);
    }
  }
  delay(100);

  for (i = 0; i < 12; i++)
  {
    if ((i % 2) == 1) {
      digitalWrite(ledPin[i], LOW);
    }
    else {
      digitalWrite(ledPin[i], HIGH);
    }
  }
  delay(100);
}

