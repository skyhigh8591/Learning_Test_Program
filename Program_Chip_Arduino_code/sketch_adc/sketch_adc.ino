void setup() {
  Serial.begin(9600);
  pinMode(A2,INPUT);
  pinMode(11,OUTPUT);

  digitalWrite(11,LOW);

}

void loop() {
  int value;
  value = analogRead(A2);
  Serial.print("value = ");
  Serial.println(value);

  if(value > 600)
  digitalWrite(11,HIGH);
  else
  digitalWrite(11,LOW);

  delay(3000);
}
