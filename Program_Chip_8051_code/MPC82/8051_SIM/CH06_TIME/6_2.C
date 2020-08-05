/********** 6_2.c ****************************
*動作：SPEAK輸出方波，設定Timer1、mode1進行延時動作
*硬體：高頻SW2-5(SPK)ON,低頻SW1-4(P1LED)ON
**********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
               //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  57600  //Timer延時時間=(1/1.8432MHz)*57600=31250uS
main()         
{
  PCON2=5; //Fosc=Fosc/32，延時時間=31250uS*32=1秒(軟體模擬無效)
//AUXR2=T1X12;  //Timer1頻率=Fosc	(軟體模擬無效)
  TMOD=0x10;  /*0001 0000,設定Timer1為mode1內部計時
                bit7:GATE=0,不使用INT1腳控制
			    bit6:C/T=0,內部計時
			    bit5-4:MODE=01，mode1 */
  TR1=1;      //啟動Timer1
  while (1)   //不斷循環執行
   {
     SPEAK=!SPEAK;           //SPEAK反相
     TL1= (65536-T) % 256; //將低8-bit計數值存入TL1 
     TH1= (65536-T) / 256; //將高8-bit計數值存入TH1
     while(TF1==0);          //等待溢位，若TF1=0自我循環
     TF1=0;                   //若計時溢位TF1=1，清除TF1=0  
   }
}
