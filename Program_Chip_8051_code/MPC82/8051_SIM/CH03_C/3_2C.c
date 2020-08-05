//*********** 3_2C.c **********************************
//*動作：定義SFR的 位元變數
//*硬體：SW1-3(P0LED)ON，按KEY1~KEY4
//******************************************************
sfr   LED  = 0x80;   //定義接腳P0名稱

sbit  LED0 = 0x80;   //定義P00接腳名稱
sbit  LED1 = LED^1;  //定義P01接腳名稱
sbit  LED2 = 0x80^2; //定義P02接腳名稱
sbit  LED3 = 0x83;   //定義P03接腳名稱

sbit  KEY1 = 0xB2;   //定義P32接腳名稱
sbit  KEY2 = 0xB3;   //定義P32接腳名稱
sbit  KEY3 = 0xEB;   //定義P43接腳名稱(軟體模擬無作用)
sbit  KEY4 = 0xEA;   //定義P42接腳名稱(軟體模擬無作用)
main()
{
  loop:
    LED0=KEY1;
    LED1=KEY2;
    LED2=KEY3;//(軟體模擬無作用)
    LED3=KEY4;//(軟體模擬無作用)    
  goto loop;
}