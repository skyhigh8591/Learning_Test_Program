/******** KEY1.C******4*4鍵盤實習範例***************
*動作：ROW0~3掃描輸出,COL0~3按鍵輸入,LED=按鍵資料輸出
*硬體：將SW1-3(P0LED)短路，按S1~S16 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
void dataout(char keyout);//按鍵資料輸出
void main()
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  LED=0xFF;      //LED暗
  while(1)   //重覆執行
  {
   ROW=0xFF;
   ROW0=ROW1=ROW2=ROW3=1;ROW0=0; //僅掃描輸出ROW0=0
   if(COL0==0) dataout(0);//若檢查COL0=0，按鍵資料輸出=0
   if(COL1==0) dataout(1);//若檢查COL1=0，按鍵資料輸出=1
   if(COL2==0) dataout(2);//若檢查COL2=0，按鍵資料輸出=2
   if(COL3==0) dataout(3);//若檢查COL3=0，按鍵資料輸出=3
       
   ROW0=ROW1=ROW2=ROW3=1;ROW1=0; //僅掃描輸出ROW1=0
   if(COL0==0) dataout(4);//若檢查COL0=0，按鍵資料輸出=4
   if(COL1==0) dataout(5);//若檢查COL1=0，按鍵資料輸出=5
   if(COL2==0) dataout(6);//若檢查COL2=0，按鍵資料輸出=6
   if(COL3==0) dataout(7);//若檢查COL3=0，按鍵資料輸出=7
       
   ROW0=ROW1=ROW2=ROW3=1;ROW2=0;   //僅掃描輸出ROW2=0
   if(COL0==0) dataout(8);  //若檢查COL0=0，按鍵資料輸出=8
   if(COL1==0) dataout(9);  //若檢查COL1=0，按鍵資料輸出=9
   if(COL2==0) dataout(0xA);//若檢查COL2=0，按鍵資料輸出=A
   if(COL3==0) dataout(0xB);//若檢查COL3=0，按鍵資料輸出=B
      
   ROW0=ROW1=ROW2=ROW3=1;ROW3=0;  //僅掃描輸出ROW3=0
   if(COL0==0) dataout(0xC);//若檢查COL0=0，按鍵資料輸出=C
   if(COL1==0) dataout(0xD);//若檢查COL1=0，按鍵資料輸出=D
   if(COL2==0) dataout(0xE);//若檢查COL2=0，按鍵資料輸出=E
   if(COL3==0) dataout(0xF);//若檢查COL3=0，按鍵資料輸出=F
  }
}
/***********************************************************
*函數名稱: dataout
*功能描述: 按鍵輸出資料送到LED顯示數字，檢查是否放開按鍵
*輸入參數：keyout
************************************************************/
void dataout(char keyout)
{
  LED=keyout;	  //按鍵資料由LED輸出
  Delay_ms(1);    //延時
  while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
  Delay_ms(1);    //延時
}
