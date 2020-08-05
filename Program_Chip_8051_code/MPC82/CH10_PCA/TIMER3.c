/******TIMER3.C******PCA軟體計時中斷範例 ************
*功能︰使用PCA軟體計時中斷，控制6個LED旋轉，間隔0.5秒
*硬體：SW1-3(P0LED)ON
****************************************************/
#include "..\MPC82.H" //暫存器及組態定義
//Fosc=22.1184MHz，PCA計數時脈=Fosc/12=1.8432MHz
#define T  7200 //軟體計時時間=(1/1.8432MHz)*7200=3906.25uS
main()         
{ P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  PCON2=7;  //Fosc=Fosc/128，軟體計時時間=3906.25uS*128=0.5秒
  CMOD = 0; //PCA計數時脈來源CPS1-0:00=Fosc/12
  CCAPM0=CCAPM1=CCAPM2=CCAPM3=CCAPM4=CCAPM5=ECOM+MAT+ECCF; 
                   //MAT=1，PAC計數與CCAP0匹配時，令CCF0=1
                   //ECOM=1，致能比較器功能
			       //ECCF=1，致能有匹配(CCFn=1)時，產生中斷
  CCAP0L=T;   CCAP0H=T>>8;     //設定模組0比較暫存器=0.5秒
  CCAP1L=T*2; CCAP1H=(T*2)>>8; //設定模組1比較暫存器=1秒
  CCAP2L=T*3; CCAP2H=(T*3)>>8; //設定模組2比較暫存器=1.5秒
  CCAP3L=T*4; CCAP3H=(T*4)>>8; //設定模組3比較暫存器=2秒
  CCAP4L=T*5; CCAP4H=(T*5)>>8; //設定模組4比較暫存器=2.5秒
  CCAP5L=T*6; CCAP5H=(T*6)>>8; //設定模組5比較暫存器=3秒

  EA = 1;            //致能所有中斷
  AUXIE = EPCA;      //致能PCA中斷
  CCF0=CCF1=CCF2=CCF3=CCF4=CCF5=0;  //清除模組0-5的比較旗標
  LED = 0xFF;
  CR = 1;            //啟動PCA計數 
  while(1);	         //空轉,等待(CH:CL)=CCAP0產生中斷
 }
/***********************************************************
*函數名稱: PCA中斷函數
*功能描述: 控制6個LED旋轉
************************************************************/
void PCA_Interrupt() interrupt 10
{ if(CCF0) LED = 0xFE;    //第0.5秒動作
  if(CCF1) LED = RL8(LED);//第1秒動作
  if(CCF2) LED = RL8(LED);//第1.5秒動作
  if(CCF3) LED = RL8(LED);//第2秒動作
  if(CCF4) LED = RL8(LED);//第2.5秒動作
  if(CCF5){LED=RL8(LED);CL=CH=0;}//第3秒動作，PCA計數器由0上數	
  CCF0=CCF1=CCF2=CCF3=CCF4=CCF5=0; //清除模組0-5的比較旗標     
}
