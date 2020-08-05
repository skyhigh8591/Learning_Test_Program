/*** MUSIC2.C*********PCA高速輸出音樂範例************
*動作：PCA高速輸出，PCA中斷控制CEX0(P12)腳輸出音樂
*硬體：SW2-6(SPK)ON
****************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "music.h"  //音頻定義
unsigned int  code Table[]  //定義音頻陣列資料,0為休止符  
   ={DO4,0,RE4,0,MI4,0,FA4,0,SO4,0,LA4,0,SI4,0,DO5,0};
char i;   //資料計數	     
unsigned int  Temp;
main()         
{
  CCAPM0 = ECOM+MAT+TOG+ECCF; //MAT=1，PAC計數與CCAP0匹配時，令CCF0=1
                              //ECOM=1，致能比較器功能
					          //TOG=1，(CH:CL)=CCAP0時，令CEX0腳反相
						      //ECCF=1，致能有匹配(CCF0=1)時，產生中斷
 
  EA = 1;       //致能所有中斷
  AUXIE = EPCA; //致能PCA中斷
  CCF0 = 0;		//清除模組0的比較旗標
  while (1)     //不斷循環執行
  {
   for(i=0; i<16; i++)   //陣列計數由0~15遞加  
    {
     if(Table[i]==0) CR = 0; //若資料=0停止PCA計數，停止發音
	  else
	  {	
	    CCAP0L=Table[i];	   //設定比較暫存器低位元組
        CCAP0H=Table[i]>>8; //設定比較暫存器高位元組
        CR = 1;             //啟動PCA計數，開始發音
	  }
     Delay_ms(1000); //延時，發音的時間，等待(CH:CL)=CCAP0產生中斷 
    }
  }
} 
/***********************************************************
*函數名稱: PCA中斷函數
*功能描述: 自動令CEX0反相
************************************************************/
void PCA_Interrupt() interrupt 10
{
  CCF0 = 0;	    //清除模組0的比較旗標
  CL = CH =0;   //PCA計數器由0開始上數
}