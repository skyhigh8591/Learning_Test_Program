void setup() {
  Serial.begin(9600);
}

void loop() {
  for(n=0;n<255;n++)
  {
    Serial.write(n);
    delay(50);
  }

}
