/****** 3_17.c*****指標 * 與 & 範例*************
*動作：令RAM位址0x10寫入計數值，
*      由LED顯示RAM(0x10)的計數值
**********************************************/
#include "..\MPC82.H"  //暫存器及組態設定	
char  count _at_ 0x10; //定義變數count在位址0x10
main() 
{
   char  i=1;     //宣告計數值 
   char  *point;  //宣告指標變數  
   point=&count;  //將變數count的位址(0x10)存入point內
loop:
   *point=i; //將計數值存入指標point內所指向的變數count內
   LED=count; //在P0顯示變數count的內容
   i++;      //計數遞加
 goto loop;
}