/************** KBI2.C *******Keypad中斷實習**********
*動作：LED遞加，若P21-0=00，則按鍵中斷成立，清除LED1
*硬體：SW1-4(P1LED),同時壓按鍵(0)~(1)，產生按鍵中斷，清除LED1
****************************************************/
#include "..\MPC82.H"
 unsigned char i=0; //定義全域變數
void main()
{
  EA = 1;          //致能所有中斷
  AUXIE = EKBI;    //致能KBI中斷
  KBMASK = 0x03 ;  //選擇P21-0有按鍵中斷

  KBCON = PATNS;   //P2有比較功能
  KBPATN = 0x0C ;  //設定若同時P21-0=00，則中斷成立

  P2_4=0;   //選擇按鍵(0)~(3)
  while(1)
  {
    LED1=~i++;	 //LED1遞加
    Delay_ms(100);
  }
}
//***********************************************
void KBI_Interrupt() interrupt 13   //Keypad中斷函數	
{ 
  i=0; 
  LED1=~i;	//清除LED1	    
  KBCON &= ~KBIF;  //清除按鍵中斷旗標KBIF=0
}
