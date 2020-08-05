/********************* IDL2.c *******************
*動作：LED0遞加輸出，由KEY1-2控制系統頻率(Fosc)調整速度，
*      在LED1顯示系統頻率(Fosc)除頻倍數
*硬體：將SW1-3(P0LED)及SW1-4(P1LED)短路，按KEY1(P32)及KEY2(P33)
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
main() 
{
 unsigned char i=0;
 char Fosc=0;
 P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
 PCON2=Fosc; //Fosc=0~7,石英晶體除頻1~128倍為系統頻率(Fosc) 
 while(1)  //重覆執行
 { 
   LED0=~i++;     //LED0遞加輸出
   LED1=~Fosc;    //LED1顯示Fosc除頻
   if(KEY1==0)   //減速
     {
	    Fosc++; 	 //系統頻率(Fosc)除頻增加 
	    if(Fosc>7) Fosc=7; //限制除頻128倍
	    PCON2=Fosc; //設定系統頻率(Fosc)
	  }	
   if(KEY2==0)     //加速
     {
        Fosc--; 	   //系統頻率(Fosc)除頻減少
	    if(Fosc<0) Fosc=0; //限制除頻1倍
	    PCON2=Fosc;	//設定系統頻率(Fosc)
	 }    
   Delay_ms(100); //Fosc除頻1倍的延時時間
  }
}
