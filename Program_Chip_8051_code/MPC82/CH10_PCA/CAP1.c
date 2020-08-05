/********** CAP1.c ********捕捉器實習範例****************
*動作：令Timer0由T0CKO(P34)輸出方波,送到CEX0(P12)捕捉輸入
*      ，在LED顯示時間差
*硬體：SW1-3(P0LED)ON，將T0CKO(P34)連接到CEX0(P12)
**********************************************/
#include "..\MPC82.H"  //暫存器及組態定義
			     //T0CKO頻率=Fosc/24/(256-TH0)
#define T  0x14  //T0CKO頻率=22118400/24/T
main()         
{
  unsigned int first;	//第一次CCAP0捕捉時間
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  AUXR2=T0CKOE; //致能T0CKO(P34)輸出方波
  TMOD=0x02;    //設定Timer0為mode2內部計時
  TH0=256-T;    //將計數值存入TH1
  TR0=1;        //啟動Timer1，不斷的由T0CKO(P34)輸出方波
  
  CCF0 = 0;		 //清除模組0的比較旗標
  CCAPM0 = CAPP+CAPN; //CAPP=1，正緣或負緣觸發輸入時，CCAP0=(CH:CL)
  CR = 1;        //啟動PCA計數 
  while(1)
   {
	 CL = CH =0;     //PCA計數器由0開始上數
	 while(CCF0==0); //等待第一次觸發輸入
	 CCF0 = 0;		 //清除PCA模組0的旗標
	 first=CCAP0L ;  //捕捉CPA計數值
	
	 while(CCF0==0); //等待第二次觸發輸入
 	 CCF0 = 0;		 //清除PCA模組0的旗標
	 LED=~(CCAP0L-first) ;//將兩次CPA計數值的時間差(T)由LED輸出
   }	
}
