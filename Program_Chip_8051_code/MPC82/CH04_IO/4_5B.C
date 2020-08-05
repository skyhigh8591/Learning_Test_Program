/********** 4_5B.C ****************************
*動作：每按一次按鍵，令LED有四種變化
*硬體：SW1-3(P0LED)ON, 按KEY1 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char flag=0;    //設定變數 
 
main() 
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)       //重覆執行 
   {		     //若flag=0，直接跳到此處
     if(KEY1==0)      //若有按鍵，flag反相
	  {
        Delay_ms(1); //延時，防止機械彈跳	   
        flag++; if(flag>3) flag=0;   
	    while(KEY1==0); //若未放開鍵，空轉 
	  }
	 if(flag==0) LED--;
 	 if(flag==1) LED++;
	 if(flag==2) LED=0;
	 if(flag==3) LED=0xFF;
	 Delay_ms(100); //延時             
   }
}