/********************** IDL1.c *******************
*動作：P0遞加超過6會進入省電模式，停止執行，在INT0(P32)
*      腳輸入負緣觸發時，會喚醒閃爍5次後，才回主程式
*硬體：將SW1-3(P0LED)短路，按KEY1(INT0)鍵。
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
main() 
{
  char i=0;
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA=1;      //致能整體中斷
  EX0=1;     //致能外部INT0斷
  IT0=1;     //設定INT0腳為負緣觸發輸入
 while(1)  //重覆執行
 {
   for(i=0;i<6;i++)
    {
      LED=~i; 
      Delay_ms(1000); //延時
    }
   //PCON=IDL;    //進入idle省電模式
   PCON=PD;	//進入power down省電模式
 }
}
//*******INT0中斷函數0，使用暫存器庫1*******
void EX1_int(void) interrupt 0 using 1  
{
  char i=0;        //定義閃爍計數變數
  unsigned int dly;
  for(i=0;i<5;i++) //閃爍計數0~4
   {
     LED=0x00; for(dly=0;dly<20000;dly++); 
     LED=0xff; for(dly=0;dly<20000;dly++); 
   }
}
