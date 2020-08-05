/*** FAST1.C*********PCA高速輸出範例************
*動作：PCA高速輸出，控制CEX0(P12)腳反相輸出。
*硬體：低頻SW1-4(P1LED)或高頻SW2-6(SPK)ON
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
//Fosc=22.1184MHz，PCA計數時脈=Fosc/12=1.8432MHz
#define T  14400  //PCA延時時間=(1/1.8432MHz)*14400=7812.5uS
main()         
{
  PCON2=7; //Fosc=Fosc/128，PCA延時時間=7812.5uS*128=1秒
  CCAPM0 = ECOM+MAT+TOG; //MAT=1，PAC計數與CCAP0匹配時，令CCF0=1
                         //ECOM=1，致能比較器功能
					     //TOG=1，(CH:CL)=CCAP0時，令CEX0腳反相
  CCAP0L=T;	    //設定比較暫存器低位元組
  CCAP0H=T>>8;  //設定比較暫存器高位元組
  CR=1;             //啟動PCA計數    
  while(1)
   {
	 CCF0 = 0;		//清除模組0的比較旗標
	 CL = CH =0;    //PCA計數器由0開始上數
	 while(CCF0==0);//等待PCA計數器(CH:CL)=CCAP0，令中斷旗標CCF0=1
   }	
}
