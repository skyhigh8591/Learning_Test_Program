void setup() {
  Serial.brgin(9600);

}

void loop() {
  n=analogRead(A0);
  Serial.println(n,DEC);
  delay(1000);

}
