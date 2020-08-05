/*** TIMER1.C*********PCA軟體計時器範例************
*動作：PCA軟體計時器延時，控制LED每秒反相一次。
*硬體：SW1-3(P0LED)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
//Fosc=22.1184MHz，PCA計數時脈=Fosc/12=1.8432MHz
#define T  14400  //軟體計時時間=(1/1.8432MHz)*14400=7812.5uS
main()         
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  PCON2=7; //Fosc=Fosc/128，軟體計時時間=7812.5uS*128=1秒
  CMOD=0;  //PCA計數時脈來源CPS1-0:00=Fosc/12
  CCAPM0 = ECOM+MAT; //MAT=1，PAC計數與CCAP0匹配時，令CCF0=1
                     //ECOM=1，致能比較器功能

  CCAP0L=T;	    //設定比較暫存器低位元組
  CCAP0H=T>>8;  //設定比較暫存器高位元組
  CR=1;         //啟動PCA計數    
  while(1)
   {
	 CCF0 = 0;		//清除模組0的比較旗標
	 CL = CH =0;    //PCA計數器由0開始上數
	 while(CCF0==0);//等待PCA計數器(CH:CL)=CCAP0，令中斷旗標CCF0=1
	 P0_0=!P0_0;	//LED反相閃爍
   }	
}
