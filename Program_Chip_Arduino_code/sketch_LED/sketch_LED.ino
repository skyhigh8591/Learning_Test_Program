
int ledPin[] = {2, 3, 4, 5, 6, 7, 8, 9};
int i;

void setup() {
  OUTPUTLED();
  OPCLOSE();
  OPCLOSE();

}


void loop() {




}

void OUTPUTLED() {


  for (i = 0 ; i < 8 ; i++)
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

  for (i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledPin[i], HIGH);
  }

  delay(1000);

  for (i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledPin[i], LOW);
  }
  delay(1000);
}

void ledOneOn() {
  for (i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledPin[i], HIGH);
    delay(1000);
  }


  for (i = 0 ; i < 8 ; i++)
  {
    digitalWrite(ledPin[i], LOW);
    delay(1000);
  }
}

void ledOneEven() {
  for (i = 0; i < 8; i++)
  {
    if ((i % 2) == 0) {
      digitalWrite(ledPin[i], HIGH);
    }
    if (i % 2) {
      digitalWrite(ledPin[i], LOW);
    }
  }
  delay(1000);

  for (i = 0; i < 8; i++)
  {
    if ((i % 2) == 1) {
      digitalWrite(ledPin[i], LOW);
    }
    else {
      digitalWrite(ledPin[i], HIGH);
    }
  }
  delay(1000);
}

