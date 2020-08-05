/********* 3_24.c*******指標及if-goto應用範例*****************
*動作：以指標方式讀取256筆陣列資料，由LED輸出
*硬體：SW1-3(P0LED)ON
**********************************************************/
#include "..\MPC82.H"  //暫存器及組態設定
#include "TABLE8.H" 
 main()
{
   unsigned char  *point;  //宣告指標變數
   P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)  
  start:        //重新開始
   point=TABLE; //將陣列資料開始位址(0x0800)存入指標變數
  loop:
   LED=~*point++;       //由LED輸出一筆資料，再位址遞加
   if(point > (TABLE+255)) goto start; //若指標超過255筆，重新開始
   Delay_ms(100);	        //延時
   goto loop;
}