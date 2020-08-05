

byte a,b,c;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

 
  Serial.println("Test 1");
  a=0x01;
  a = a << 3;
  Serial.println("a = 0 x 01 << 3 in BIN : ");
  Serial.println(a,BIN);
  Serial.println(a,HEX);
  Serial.println(" ");


  a=0x03;
  a = a << 5;
  Serial.println("a = 0 x 01 << 5 in BIN : ");
  Serial.println(a,BIN);
  Serial.println(a,HEX);
  Serial.println(" ");

  a=(0x1 << 3) | (0x3 << 5);
  Serial.println("a = (0x1 << 3) | (0x3 << 5) in BIN : ");
  Serial.println(a,BIN);
  Serial.println(a,HEX);
  Serial.println(" ");

  Serial.println("Test 2");
  a=B11111111;
  b=B11111100;
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0xfc ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  a=B11111111;
  b= ~0x03;
  Serial.println("b =  ");
  Serial.println(b,BIN);
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0xfc ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  Serial.println("Test 3");
  a=B11111111;
  b=B10011111;
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0x9f ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  a=B11111111;
  b= ~ (0x03 << 5);
  Serial.println("b =  ");
  Serial.println(b,BIN);
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0x9f ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  Serial.println("Test 4");
  a=B11111111;
  b=B11000111;
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0xc7 ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  a=B11111111;
  b= ~ (0x07 << 3);
  Serial.println("b =  ");
  Serial.println(b,BIN);
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0xc7 ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");



  a=B11111111;
  b= ~ (0x0f << 3);
  Serial.println("b =  ");
  Serial.println(b,BIN);
  a=a&b;
  Serial.println("a=0xff ");
  Serial.println("b=0x87 ");
  Serial.print("a=a&b in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");

  a=B11111111;
  b=~ 0x3;
  Serial.println("b =  ");
  Serial.println(b,BIN);
  a=a&b;
  Serial.println("a =  ");
  Serial.println(a,BIN);
  c=0x02;
  a=a|c;
  Serial.println("a=0xff ");
  Serial.println("b=0xfc ");
  Serial.print("a= (a&b)|c in BIN : ");
  Serial.println(a,BIN);
  Serial.println(" ");
  
}
void loop() {


}


