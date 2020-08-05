/******** KEY5A.C******4*4外部中斷實習範例***************
*動作：ROW0~3掃描輸出,COL0~3按鍵輸入,在LED輸出
*硬體：SW1-3(P0LED)短路，J15(INT0)短路，按S1~S16 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
unsigned char Table[8]=0; 

void main()
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA=1; EX0=1;    //致能外部中斷
  LED=~0;         //初始顯示0
  ROW=0x0F;       //掃描輸出=0000

  DI=1; DO=1; CS=0; SK=0;//設定初值
  EWEN();                //致能EEPROM寫入及清除
  ERAL();                //EEPROM清除全部記憶體
  while(1);       //等待按鍵，此時可做其它工作
}
 //***********************************************
void INT0_Interrupt() interrupt 0   //INT0中斷函數	
{ 
   unsigned char key=0;	    //宣告按鍵計數
   unsigned char scan=0xEF;  //按鍵掃描令ROW0=0，其餘為1
   while(1)
   {
     ROW=scan;		  //掃描輸出
	 if(!(COL0 & COL1 & COL2 & COL3)) break;//若COL0~3其中之一為0，退出顯示 
     scan=RL8(scan); //左旋轉，換掃下一列,令ROW0~3輪流為0
     key=key+4;	//基數+4
   }
   if(COL0==0) LED=~key; //檢查COL0列，若有按鍵計數輸出
   key++;                //若不是按鍵計數遞加  
   if(COL1==0) LED=~key; //檢查COL1列，若有按鍵計數輸出
   key++;                //若不是按鍵計數遞加
   if(COL2==0) LED=~key; //檢查COL2列，若有按鍵計數輸出
   key++;                //若不是按鍵計數遞加
   if(COL3==0) LED=~key; //檢查COL3列，若有按鍵計數輸出

   Delay_ms(1);//處理按鍵跳動之延遲   
   while(!(COL0 & COL1 & COL2 & COL3));//若COL0~3≠1111未放開按鍵
   Delay_ms(1);//處理按鍵跳動之延遲	
   ROW=0x0F;   //掃描輸出=0000    
   }
