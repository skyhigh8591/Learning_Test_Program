/********** MUSIC2B.c ****************************
*動作：設定以Timer0計時中斷，令喇叭輸出音樂，
*      同時P0LED遞加可調整速度
*硬體：P10-->BUZZER、P00~7-->低態亮LED、P32-->KEY1及P33-->KEY2整音樂的速度
************************************************/
#include "..\MPC82.H"   //暫存器及組態定義

#include "music.h"  //音頻定義
code unsigned int Table[] =	// 虹彩妹妹
{
	DO3, 	RE3,		MI3,		DO3,		SO4,
	MI3,		RE3,		SO4,
	RE3,		DO3,		LA2,		MI3,		DO3,		SI2,
	SI2,			LA2,
	SI3,			DO3,		RE3,		SO2,		DO3,
	RE3,		MI3,		FA4,		FA4,		MI3,	RE3,		DO3,		RE3,
	DO3,		RE3,		MI3,		DO3,		SO4,
	MI3,		RE3,		SO4,		
	RE3,		DO3,		LA2,		LA2,		SI2,		DO3,		SO3,
	SO2,		LA2,		SI2,			DO3,		RE3,	SO2,		DO3,		RE3,		MI3,		FA4,
	FA4,		MI3,		RE3,		DO3,		DO3,	
};

code unsigned char Delay[] =	 // 節拍延時,以4分音符為1拍
{
	4,4,4,4,8,
	4,4,8,
	4,4,4,4,4,8
	4,8,
	4,4,4,4,8,
	4,4,4,4,4,4,4,8,
	4,4,4,4,8,
	4,4,8,
	4,4,4,4,4,4,8,
	4,4,4,4,4,4,4,4,4,8,
	4,4,4,4,8,
};
unsigned char  i=0,j,k=50;   //資料計數
main()
{ 
 TMOD=0x01;   //設定Timer0為mode1內部計時 
 EA=1;ET0=1;  //致能Timer0中斷
 while (1)    //不斷循環執行
  {
   for(i=0; i<sizeof(Table)/2; i++)   //陣列計數遞加  
    {
    
	 P0=~j++;      //變數i反相送到P0及P1輸出(設中斷點)
	 if(KEY1==0) {k++; if(k>250) k=250;}
	 if(KEY2==0) {k--; if(k<5) k=5;}
 
     if(Table[i]==0) TR0=0; //若資料=0為停止Timer0計時
	  else
	  {	
	   TL0=Table[i];TH0=Table[i] >>8; //設定計時值     
       TR0=1;            //啟動Timer0開始計時
	  }
     Delay_ms(Delay[i]*k);     //音長 
    }
  }
}
/***************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
{
  TL0=Table[i] ; TH0=Table[i] >>8; //重新設定計時值
  SPEAK=!SPEAK;     //喇叭反相輸出
}
 