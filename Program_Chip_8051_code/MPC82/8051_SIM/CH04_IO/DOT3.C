/***** DOT3.c ****點矩陣顯示器反白閃爍字型**************
*動作：顯示字型反白閃爍字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
*硬體：SW1-2(LED8X8)ON
**********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "font.h"  //字型資料檔
main() 
{ 
  char i;       //定義陣列資料計數
  unsigned char repeat;  //定義重覆掃描次數	 
  bit invert=0;          //定義反白顯示旗標  
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  Scan=0x7F; //由com1開始掃瞄 
 while(1)
 {
   for(repeat=0;repeat<200;repeat++) //重覆掃瞄次數
    {
      for(i=0;i<8;i++)   //讀取8筆資料掃瞄8次
       {
         if(invert==0) Data=font[i];//若旗標=0，讀取陣列資料輸出
	 else Data=~font[i]; //若旗標=1，讀取陣列資料反相輸出
          Delay_ms(1);    //延時
	  Data=0xFF;      //全暗
          Scan=RR8(Scan); //換掃瞄下一行
       }
     } 
   invert=!invert;     //反白旗標反相   
  } 
}