/********** 4_5A.C ****************************
*動作：每按一次按鍵，超過1秒以才令LED遞加
*硬體：SW1-3(P0LED)ON, 按KEY1 
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
int flag=0;    //設定變數 
 
main() 
{
  unsigned char i=0;
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  while(1)       //重覆執行 
   {		     
     LED=~i; 
	 while(KEY1==0)    //若有按鍵，flag遞加
	  {
       Delay_ms(1); //延時，防止機械彈跳	   
       flag++;    	//flag遞加
       if(flag>1000) flag=1000;    	//flag遞加
	  }
     Delay_ms(1); //延時，防止機械彈跳
	 if(flag==1000) i++; 
	 
	 flag=0;
   }
}