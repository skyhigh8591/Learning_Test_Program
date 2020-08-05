
int x1 , x2 , y;
char ch1;
char ch2[5]={0x30,0x31,0x32,0x33,0x34};
char ch3[6]="abcde";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println(78, DEC); //十進位
  Serial.println(78, BIN); //二進位
  Serial.println(78, OCT); //八進位
  Serial.println(78, HEX); //十六進位
  Serial.println(1.23456, 2); //取後兩位
  Serial.println(1.23456, 5); //取後五位

  x1 = 0x80;
  Serial.print("X1 = 0x80 in DEC : ");
  Serial.println(x1, DEC);
  Serial.println(" ");

  x1 = 0x7fff;
  Serial.print("X1 = 0x7fff in DEC : ");
  Serial.println(x1, DEC);
  Serial.println(" ");

  x1 = 0x8000;
  Serial.print("X1 = 0x8000 in DEC : ");
  Serial.println(x1, DEC);
  Serial.println(" ");

  x1 = 0xffff;
  Serial.print("X1 = 0xffff in DEC : ");
  Serial.println(x1, DEC);
  Serial.println(" ");

  x1 = -1;
  x2 = -10;
  y=x1+x2;
  Serial.print("y = -1 + (-10) in DEC : ");
  Serial.print(y,DEC);
  Serial.println(" ");

  y = x1+10;
  Serial.print("y = -1 + 10 in DEC : ");
  Serial.print(y,DEC);
  Serial.println(" ");
  
  //計算超出 錯誤不會提示
  x1=10;
  x2=0x7ffff;
  y = x1+x2;
  Serial.print("y = 10 + 32767 in DEC : ");
  Serial.print(y,DEC);
  Serial.println(" ");
  
  //計算超出 錯誤不會提示
  x1=-10;
  x2=-32767;
  y = x1+x2;
  Serial.print("y = -10 + -32767 in DEC : ");
  Serial.print(y,DEC);
  Serial.println(" ");


  ch1=0x30;
  Serial.print("ch1 = 0x30 , the char = ");
  Serial.println(ch1);
  Serial.println(" ");

  ch1=0x41;
  Serial.print("ch1 = 0x41 , the char = ");
  Serial.println(ch1);
  Serial.println(" ");

  ch1='9';
  Serial.print("ch1 = '9' , the ASCII code = ");
  Serial.println(ch1,HEX);
  Serial.println(" ");

  ch1='x';
  Serial.print("ch1 = 'x' , the ASCII code = ");
  Serial.println(ch1,HEX);
  Serial.println(" ");

  
  Serial.print("char 2 = ");
  Serial.println(ch2);
  Serial.println(" ");

  Serial.print("char 3 =");
  Serial.println(ch3);
  Serial.println(" ");

  for(int i = 0 ; i < 5 ; i++)
  {
    ch1 = ch3[i];
    Serial.print("string value = ");
    Serial.println(ch1,HEX);
  }








  
}
void loop() {
  // put your main code here, to run repeatedly:

}
