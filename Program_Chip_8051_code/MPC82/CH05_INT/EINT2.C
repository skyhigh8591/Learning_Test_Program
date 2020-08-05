/********* EINT2.c ********外部中斷範例**********************
*動作：INT0(P32)腳輸入負緣觸發時，LED0閃爍50次
*      INT1(P33)腳輸入負緣觸發時，LED0遞加50次
*      INT2(P43)腳輸入負緣觸發時，LED1閃爍50次
*      INT3(P42)腳輸入負緣觸發時，LED1遞加50次
*硬體：反相輸出，將SW1-3(P0LED)及SW1-4(P1LED)短路，按KEY1-4鍵。
***********************************************/
#include "..\MPC82.H"   //暫存器及組態定義
main()
{
  unsigned char  j=0;      //定義變數=0
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA=1;          //致能整體中斷
  EX0=1; EX1=1; EX2=1;EX3=1;//致能外部INT0~3中斷
  IT0=1; IT1=1; IT2=1;IT3=1;//設定INT0~3腳負緣觸發中斷
  PX1=1;        //設定INT1中斷優先
  while(1);     //等待INT0-3中斷
}
/*********************************/
void EX0_int(void) interrupt 0   //INT0中斷函數0
{
  char i;
  for(i=0;i<50;i++) //閃爍計數
   {
     LED0=0x00;Delay_ms(100); 
     LED0=0xff;Delay_ms(100);
   }
}
/*********************************************/
void EX1_int(void) interrupt 2   //INT1中斷函數2
{
  char i; 
  unsigned int dly;     
  for(i=0;i<50;i++)   //計數遞加
   {
     LED0=~i;
	 dly=50000; while(dly--);
   }
}
/*********************************************/
void EX2_int(void) interrupt 6   //INT2中斷函數6
{
 char i;
  unsigned int dly;
  for(i=0;i<50;i++) //閃爍計數
   {
     LED1=0x00;dly=50000; while(dly--); 
     LED1=0xff;dly=50000; while(dly--);
   }
}
/*********************************************/
void EX3_int(void) interrupt 7   //INT3中斷函數7
{
  char i; 
  unsigned int dly;     
  for(i=0;i<50;i++)   //計數遞加
   {
     LED1=~i;
	 dly=50000; while(dly--);
   }
}
