/********** MUSIC2A.c ****************************
*動作：設定以Timer0計時中斷，令喇叭輸出各種音頻
*硬體：SW2-5(SPK)ON
************************************************/
#include "..\MPC82.H"   //暫存器及組態定義

#include "music.h"  //音頻定義
code unsigned int Table[] =	// 虹彩妹妹
{
	LA3, SO3, MI3, LA3, SO3, MI3,
	LA3, LA3, SO3, LA3,
	LA3, SO3, MI3, LA3, SO3, MI3,
	RE3, RE3, DO3, RE3,
	MI3, MI3, SO3, LA3, DO4, LA3, SO3,
	MI3, MI3, SO3, DO3,
	MI3, MI3, MI3, MI3, MI3,
	LA2, LA2, SO2, LA2,
};

code unsigned char Delay[] =	 // 節拍延時,以4分音符為1拍
{
	8, 4, 4, 8, 4, 4,    //32
	4, 4, 8, 16,	     //32
	8, 4, 4, 8, 4, 4,    //32
	4, 4, 8, 16,	     //32
	8, 4, 4, 4, 4, 4, 4, //32
	4, 8, 4, 16,		 //32
	8, 8, 8, 4, 4,		 //32
	4, 8, 4, 16			 //32
};
char i;   //資料計數
main()
{ 
 TMOD=0x01;   //設定Timer0為mode1內部計時 
 EA=1;ET0=1;  //致能Timer0中斷
 while (1)    //不斷循環執行
  {
   for(i=0; i<sizeof(Table)/2; i++)   //陣列計數由0~15遞加  
    {
     if(Table[i]==0) TR0=0; //若資料=0為停止Timer0計時
	  else
	  {	
	   TL0=Table[i];TH0=Table[i] >>8; //設定計時值     
       TR0=1;            //啟動Timer0開始計時
	  }
     Delay_ms(Delay[i]*50);     //音長 
    }
  }
}
/***************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
{
  TL0=Table[i] ; TH0=Table[i] >>8; //重新設定計時值
  SPEAK=!SPEAK;     //喇叭反相輸出
}
