/********** 6_3.c *****************************
*動作：LED遞加，設定以Timer1、mode1、由INT1腳啟
*      動計時的延時動作
*硬體：SW1-3(P0LED)ON，按KEY2(INT1)停止
**********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void Delay(void);  //宣告延時函數
               //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  57600  //Timer延時時間=(1/1.8432MHz)*57600=31250uS
main()         
{
   unsigned char i=0;
   P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
   PCON2=5; //Fosc=Fosc/32，延時時間=31250uS*32=1秒(軟體模擬無效)
   TMOD=0x90; /*1001 0000,設定Timer1的GATE=1及mode1
                bit7:GATE=1,使用INT1腳啟動計時
			    bit6:C/T=0,內部計時
			    bit5-4:MODE=01，mode1 */				 
   TR1=1;       //啟動Timer1
   while(1)    //不斷循環執行
   {
     LED=~i++;   //LED遞加輸出
     Delay();    //延時函數
   }
}
/********************************************/
void Delay(void)  //延時函數
{
  TL1=65536-T;      //將低8位元計數值存入TL1 
  TH1=(65536-T)>>8; //將高8位元計數值存入TH1
  while(TF1==0);    //等待計時溢位，若TF1=0自我循環
  TF1=0;   //若計時溢位TF1=1，清除TF1=0
}
