/***** KEY6A.C******4*4掃描按鍵中斷(KBI)實習範例***************
*動作：ROW0~3掃描輸出,COL0~3按鍵輸入,在LED輸出
*硬體：SW1-3(P0LED)短路，按S1~S16 
**********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
unsigned char count=0;  //基數=0
void main()
{
  unsigned char scan=0xEF;  //按鍵掃描令ROW0=0，其餘為1
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA = 1;            //致能所有中斷
  AUXIE = EKBI;      //致能KBI中斷
  KBMASK = 0x0F ;    //選擇P23-0有按鍵中斷
  LED1=~count;       //初始顯示0
  ROW=0x0F;          //掃描輸出=0000
  while(1);          //等待按鍵，此時可做其它工作
}
 //***********************************************
void KBI_Interrupt() interrupt 13   //Keypad中斷函數	
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
  KBCON &= ~KBIF;  //清除按鍵中斷旗標KBIF=0
  ROW=0x0F;   //掃描輸出=0000    
}
