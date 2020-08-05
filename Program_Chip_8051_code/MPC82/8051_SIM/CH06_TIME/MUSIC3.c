/**********MUSIC3.c**** 電子琴範例**********
*動作：按鍵0~9，令喇叭輸出各種音頻
*硬體：SW2-5(SPK)ON，按鍵S1~S10
************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "music.h"  //音頻定義
void dataout(char keyout);    //按鍵輸出

unsigned int  code Table[] //音頻的列表資料，按鍵0~9的音頻  
       = {SI2,DO3,RE3,MI3,FA3,SO3,LA3,SI3,DO4,RE4};
unsigned char   i=0;    //資料計數
void main()
{
   unsigned char count=0;  //按鍵計數
   unsigned char scan=0xEF;  //按鍵掃描令ROW0=0，其餘為1
   
   TMOD=0x01;   //設定Timer0為mode1內部計時 
   EA=1;ET0=1;  //致能Timer0中斷
 
  while(1)   //重覆執行
  {
    if(count>15){scan=0xEF;count=0;}//若計數>15，從頭開始
    ROW=scan;	  //掃描輸出
    if(COL0==0) dataout(count);//檢查COL0列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL1==0) dataout(count);//檢查COL1列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL2==0) dataout(count);//檢查COL2列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    if(COL3==0) dataout(count);//檢查COL3列，若是計數輸出
    count++; Delay_ms(1);      //若不是，計數+1
    scan=RL8(scan); //左旋轉，換掃下一列,令ROW0~3輪流為0
  }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵讀取音頻資料發出聲音，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout) 
{	
    i=keyout; //按鍵計數存入資料計數
	TL0=Table[i];TH0=Table[i] >>8; //設定計時值     
    TR0=1;             //啟動Timer0開始計時, 發出聲音
    Delay_ms(1);    	//處理按鍵跳動之延遲   
    while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
    Delay_ms(1);       	//處理按鍵跳動之延遲
    TR0=0;              //停止Timer0計時，停止輸出音頻 
}
/***************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
{
  TL0=Table[i]; TH0=Table[i] >>8; //重新設定計時值
  SPEAK=!SPEAK;     //喇叭反相輸出
}

 