/********** 6_5.c *****************************
*動作：設定Timer1的mode2進行延時動作
*硬體：高頻SW2-5(SPK)ON,低頻SW1-4(P1LED)ON
***************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
               //Fosc=22.1184MHz，Timer時脈=Fosc/12=1.8432MHz
#define T  225  //Timer延時時間=(1/1.8432MHz)*225=122.0703125uS
main()         
{
 PCON2=7;//Fosc=Fosc/128，時間=122.0703125uS*128=15625uS(軟體模擬無效)
  TMOD=0x20;  /*0010 0000,設定Timer1為mode2內部計時
	            bit7:GATE=0,不使用INT1腳啟動計時
	            bit6:C/T=0,內部計時
	            bit5-4:MODE=10，mode2 */
  TL1=TH1=256-T; //將8位元計數值存入TL1及TH1
  TR1=1;         //啟動Timer1 
  while (1)      //不斷循環執行
   {
     SPEAK=!SPEAK; //SPEAK反相
	   while(TF1==0); //等待計時溢位，若TF1=0自我循環
     TF1=0;  //若計時溢位TF1=1，TH1自動載入TL1，清除TF1=0
   }
}
