/************** KBI1.C *******Keypad中斷實習**********
*動作：LED1遞加，若P21-0其中一個為0，則按鍵中斷成立，清除LED1
*硬體：SW1-4(P1LED)，壓按鍵(0)或(1)，產生按鍵中斷，清除LED1
****************************************************/
#include "..\MPC82.H"
   unsigned char i=0; //定義全域變數
void main()
{
  EA=1; AUXIE=EKBI;//致能KBI中斷
  KBMASK = 0x03;   //選擇P21-0有按鍵中斷
  P2_4=0;          //由按鍵(0)~(3)輸入
  while(1)
  {
    LED1=~i++;	   //LED1遞加
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
