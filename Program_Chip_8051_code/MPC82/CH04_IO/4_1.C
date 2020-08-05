/********** 4_1.c *****************************
*動作：喇叭(SPEAK)輸出嗶嗶聲
*硬體：SW2-5(SPK)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#define F     600	//定義音頻常數
#define T     600	//定義音長常數
#define STOP  1000	//定義停止時間常數

main() 
{
  unsigned int i,dly;
  P1M0=0; P1M1=0x01; //設定P10(SPK)為推挽式輸出(M0-1=01)
  while(1)
  {
	for(i=0;i<T;i++) //輸出反相次數，決定音長
     {
	    SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
		dly=F; while(dly--);  //音頻延時
     }
	SPEAK=0; Delay_ms(STOP); //喇叭停止，間隔時間
  }
}
