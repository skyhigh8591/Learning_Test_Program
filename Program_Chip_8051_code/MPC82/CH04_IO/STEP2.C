/*********** STEP2.C ***************************************
*動作：將驅動數碼存在陣列資料內，以手動方式控制步進馬達運轉                             
*      KEY1=控制正反轉，1=正轉，0=反轉。
*      KEY2=控制運轉/停止，1=運轉，0=停止
*      KEY3=控制減速，1=不變，0=減速
*      KEY4=控制加速，1=不變，0=加速
*硬體：SW1-3(P0LED)ON及SW2-1~4(STEP)ON,按鍵KEY1~4
********************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
unsigned char run_Table[]={0x1,0x2,0x4,0x8};//驅動數碼
void main()
{
  char i;     //定義資料計數
  unsigned int speed=100; //定義馬達速度變數初值
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  P1M0=0; P1M1=0xF0; //設定P17-4(STEP)為推挽式輸出(M0-1=01)
  STEP=0x0F;   //步進馬達初值：P17-4=0000
  while(1) 
   {
     while(KEY2==0);    //若KEY2=0，停止運轉
	  if(KEY3==0) 	    //若KEY3=0減速
	  {speed++; if(speed>1000) speed=1000;} // 限制時間
	 
	  if(KEY4==0)      //若KEY4=0加速
	  {speed--; if(speed<10) speed=10;} // 限制時間 
	  
     if(KEY1==1)         //若KEY2=1，KEY1=1，馬達正轉
     {
      if(i>3) i=0;       //若資料計數>3，從0開始
      LED=~run_Table[i];    //讀取驅動數碼由LED輸出 
      STEP=run_Table[i]<<4; //讀取驅動數碼由步進馬達輸出 
      Delay_ms(speed);   //延時時間 
      i++;               //資料計數+1	  
     }
       else              //若KEY2=1，KEY1=0，馬達反轉
        {
         if(i<0) i=3;       //若資料計數<0，從3開始   
         LED=~run_Table[i];   //讀取驅動數碼由LED輸出 
	 STEP=run_Table[i]<<4; //讀取驅動數碼由步進馬達輸出
         Delay_ms(speed);   //延時時間
         i--;               //資料計數-1       
      }
  }
}
