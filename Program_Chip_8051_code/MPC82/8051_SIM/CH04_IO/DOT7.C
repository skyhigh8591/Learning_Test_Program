/***** DOT7.c ****點矩陣顯示器布簾下拉字型**************
*動作：顯示布簾下移位字型
*接線：Scan低電位掃描輸出，由Data低電位輸出資料
*硬體：SW1-2(LED8X8)ON
**********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
#include "font.h"  //字型A資料檔
main() 
{ 
  unsigned char i;      //定義陣列資料計數
  unsigned int repeat; //定義重覆掃描次數		 
  unsigned char mask;   //定義遮蔽資料 
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  Scan=0x7F;   //由com1開始掃瞄 
  mask=0xFF;   //全部遮蔽  
  while(1)
  {
    mask=mask >> 1;//減少要遮蔽部份
	for(repeat=0;repeat<100;repeat++) //重覆掃瞄次數
     {				     
       for(i=0;i<8;i++)  //讀取8筆資料掃瞄8次
       {
        Data=font[i] | mask;//讀取陣列資料，並遮蔽輸出
        Delay_ms(1);   //延時
        Data=0xff;     //全暗
	    Scan=RR8(Scan);//換掃瞄下一行
       }
     }
   if(mask==0) mask=0xFF;    //若移位到0，全部遮蔽
  } 
}