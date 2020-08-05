/******* UART7.c ***********串列埠函數發射***************
*動作：以putchar()函數串列發射陣列字元到電腦UART
*硬體：SW3-3(TxD1)ON
***********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include <stdio.h>  //加入標準輸出入函數
char code TABLE[] = {"abcdefghijklmnop"};//定義陣列常數 
main()
{
  char i;   //定義陣列計數變數
  UART_init(9600);  //設定串列環境及鮑率
  TI=1;
  for(i=0;i<16;i++)  //陣列計數變數=0~16
   {
     putchar (TABLE[i]); //由串列埠發射一個字元
     putchar('\n');     //跳行
   }
    putchar('\n');       //跳行    
  puts("ABCDEFGHIJKLMNOP"); //由串列埠發射一個字串   
  while(1);  //自我空轉
}
/***********************************************************
*函數名稱: UART_init
*功能描述: UART啟始程式
*輸入參數：bps
************************************************************/
void UART_init(unsigned int bps)  //UART啟始程式
{  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
   SCON = 0x50;     //設定UART串列傳輸為MODE1及致能接收
   TMOD = 0x20;     //設定TIMER1為MODE2
   TH1 = 256-(57600/bps);  //設計時器決定串列傳輸鮑率
   TR1 = 1;          //開始計時
}