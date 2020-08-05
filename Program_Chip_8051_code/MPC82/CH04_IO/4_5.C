/********** 4_5.C ****************************
*動作：每按一次按鍵，控制LED遞加輸出或停止
*硬體：SW1-3(P0LED)ON, 按KEY1 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
bit flag=1;    //設定bit變數 
 
main() 
{
  unsigned char i=0;
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)       //重覆執行 
   {		     //若flag=0，直接跳到此處
     if(KEY1==0)      //若有按鍵，flag反相
	  {
           Delay_ms(1); //延時，防止機械彈跳	   
           flag=!flag;    //flag反相
	   while(KEY1==0); //若未放開鍵，空轉 
           Delay_ms(1); //延時，防止機械彈跳
	  }
	 if(flag==0) continue;//若flag=0，直接跳到迴圈最前面
 	 LED=~i++;		    //若flag=1,LED遞加輸出
	 Delay_ms(100); //延時             
   }
}