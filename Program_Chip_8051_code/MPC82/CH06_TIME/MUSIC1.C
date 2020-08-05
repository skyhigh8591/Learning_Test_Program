/********** music1.c **********************************
*動作：設定以Timer0計時中斷mode1、令喇叭輸出指定音頻
*硬體：SW2-5(SPK)ON
******************************************************/
#include "..\MPC82.H"   //暫存器及組態定義

#define  t      22118400/12/2 //T=Fosc/12/2=基本頻率
#define  DO     65536-t/523   //各種音頻的計時器內容
#define  RE     65536-t/587
#define  MI     65536-t/659
#define  FA     65536-t/698
#define  SO     65536-t/785
#define  LA     65536-t/880
#define  SI     65536-t/998	     

unsigned int  code Table[] //音頻的陣列資料 
        = { DO,RE,MI,FA,SO,LA,SI };
unsigned int  Temp;
main()
{
 char i;
 EA=1;ET0=1;    //致能Timer0中斷
 TMOD=0x01;   //設定Timer0的mode1工作
 while(1)      //重覆執行
  {
   for(i=0;i<7;i++) //輸出7個音階
    {
     Temp=Table[i]; //讀取陣列音頻資料
     TL0=Temp; TH0=Temp >> 8; //音頻資料存入計時值     
     TR0=1;         //啟動Timer0開始計時
     Delay_ms(500); //延時，發音的時間
     TR0=0;         //停止Timer0計時 
    }
		SPEAK = 0;
    Delay_ms(1000);   //延時，停止發音的時間
  }
}
/***********************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
{
   TL0=Temp;  TH0=Temp >> 8;   //重新設定計時值   
   SPEAK=!SPEAK;   //喇叭反相發出聲音
}
