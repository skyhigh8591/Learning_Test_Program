/********** 6_1.c ****************************
*動作：SPEAK輸出方波，設定Timer0、mode0進行延時動作
*硬體：高頻SW2-5(SPK)ON,低頻SW1-4(P1LED)ON
**********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
                   //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  7200  //Timer延時時間=(1/1.8432MHz)*7200=3906.25uS
main()         
{
  PCON2=7;//Fosc=Fosc/128，延時時間=3906.25uS*128=0.5秒(軟體模擬無效)
  //AUXR2=T0X12;  //Timer0頻率=Fosc(軟體模擬無效)
  TMOD=0x00;  /*0000 0000 設定Timer0為mode0內部計時 
                bit3:GATE=0,不使用INT0腳控制
			    bit2:C/T=0,內部計時
			    bit1-0:MODE=00，模式0 */
  TR0=1;        //啟動Timer0
  while (1)    //不斷循環執行
   {  
     SPEAK=!SPEAK; //SPEAK反相
     TL0=(8192-T) % 32; //將低5-bit計數值存入TL0 
  	  TH0=(8192-T) / 32; //將高8-bit計數值存入TH0
  	  while(TF0==0);  //等待計時溢位，若TF0=0自我循環
  	  TF0=0;  //若計時溢位TF0=1，清除TF0=0 
   }
}