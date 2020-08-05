/********** UART9.c ****************************
*動作：令UART2鮑率產生器由S2CKO(P35)輸出方波
*硬體：S2CKO(P35)腳連接P10，低頻SW1-4(P1LED)ON，高頻SW2-5(SPK)ON
**********************************************/
#include "..\MPC82.H"  //暫存器及組態定義
			    //S2CKO頻率=Fosc/24/(256-S2BRT)
#define T  225  //S2CKO頻率=22118400/24/225=4096Hz
main()         
{
  PCON2=7;	     //Fosc=Fosc/128，S2CKO頻率=4096Hz/128=32Hz
  S2BRT=256-T;       //將計數值存入S2BRT
  AUXR2=S2CKOE+S2TR; //致能S2CKO(P35)輸出方波，啟動鮑率產生器
  while (1);    //不斷循環執行
}
