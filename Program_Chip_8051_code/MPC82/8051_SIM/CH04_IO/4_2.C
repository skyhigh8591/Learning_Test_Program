/********** 4_2.c *****************************
*動作：喇叭(SPEAK)輸出嗶嗶聲，按下KEY1時，喇叭停止
*硬體：SW2-5(SPK)ON，按KEY1
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#define F     600	//定義音頻常數
#define T     600	//定義音長常數
#define STOP1  300	//定義嗶聲的間隔時間
#define STOP2  1000	//定義間隔時間

void beep(unsigned char i); 

main() 
{
  P1M0=0;    P1M1=0x01; //設定P10(SPK)為推挽式輸出(M0-1=01)
  while(1)
  {
    beep(1);        //嗶一聲
    SPEAK=0; Delay_ms(STOP2); //喇叭停止，間隔時間
    beep(2);        //嗶二聲
    SPEAK=0; Delay_ms(STOP2); //喇叭停止，間隔時間
    beep(3);        //嗶三聲
    SPEAK=0; Delay_ms(STOP2); //喇叭停止，間隔時間
  }
}
/********************************************/
void beep(unsigned char i)
{
  unsigned int  j,dly;//SPEAK反相次數
  while(i--)   //嗶聲次數
   {
     for(j=0;j<T;j++) //輸出反相次數，決定音長
      {
        while(KEY1==0) SPEAK=0;	// 按下KEY1時，喇叭停止
	    SPEAK=!SPEAK; //SPEAK反相,令喇叭發出聲音
	    dly=F; while(dly--);//音頻延時
      }
	SPEAK=0; Delay_ms(STOP1);//喇叭停止，嗶聲的間隔時間
  }
}
