/***** DOT2B.c ******8*8點矩陣固定字型上下鏡射範例*****
*動作：輸出陣列字型資料，顯示上下鏡射的字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
*硬體：SW1-2(LED8X8)ON
************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "font.h"  //字型資料檔

char bdata j;	//宣告變數在位元定址區
sbit b0=j^0;	//設定位元變數
sbit b1=j^1;
sbit b2=j^2;
sbit b3=j^3;
sbit b4=j^4;
sbit b5=j^5;
sbit b6=j^6;
sbit b7=j^7;
main() 
{ 
  char i; //定義陣列資料計數
  Scan=0x7F;       //由com1開始掃瞄輸出  

  while(1)		  
  {
    for(i=0;i<8;i++)   //讀取8筆資料掃瞄8次
     {
       j=font[i]; //將字型陣列資料讀出，放入j中
                      
       P0_0 = b7; //P0_0~P0_7對應到位元定址區的b7~b0
       P0_1 = b6;
       P0_2 = b5;
       P0_3 = b4;
       P0_4 = b3;
       P0_5 = b2;
       P0_6 = b1;
       P0_7 = b0;       

       //Data=font[i]; //若將自行直接輸出時，會上下鏡射
       Delay_ms(1);    //延時
       Data=0xFF;      //全暗	       
       Scan=RR8(Scan); //換掃瞄下一行
     } 
  } 
} 