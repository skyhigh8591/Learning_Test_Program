/*******3_21A.c*********************** 
*動作：強制轉換運算式型態範例
**********************************/
main()
{
   char   a=-2; 	//a=-2=0xFE=1111 1110
   unsigned char   b=0xFE; 	//b=0xFE=1111 1110
   bit c=1;           //1-bit變數
   unsigned char   d; //8-bit變數
   static unsigned char i;  //宣告無符號8-bit變數
  loop: 
   i=a>>1;  //i=0xFF,將a會符號位元複製右移    
   i=(unsigned  char) a>>1; //i=0x7F,轉換為無符號變數，由0遞補右移
   c=(bit)(b & 0x01); //c=0,將8-bit變數轉換為1-bit數
   d=(unsigned char) (!c); //d=1,將1-bit變數轉換為8-bit數
   goto loop;  
}
