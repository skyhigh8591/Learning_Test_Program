/********** FRE4.c ****************************
*動作：令Timer0由T0CKO(P34)輸出方波
*硬體：T0CKO(P34)腳連接P10，低頻SW1-4(P1LED)ON，高頻SW2-5(SPK)ON
**********************************************/
#include "..\MPC82.H"  //暫存器及組態定義
	        //T0CKO頻率=Fosc/24/(256-TH0)
#define T  225  //T0CKO頻率=22118400/24/225=4096Hz
main()         
{
  PCON2=7;	//Fosc=Fosc/128，T0CKO頻率=4096Hz/128=32Hz
  AUXR2=T0CKOE; //致能T0CKO(P34)輸出方波
  TMOD=0x02;    //設定Timer0為mode2內部計時
  TH0=256-T;    //將計數值存入TH1
  TR0=1;        //啟動Timer1
  while (1);    //空轉，此時T0CKO(P34)腳不斷輸出方波
}
