/********** EINT1.c ********外部中斷範例***************
* 動作：LED0遞加，INT0腳輸入0準位或負緣觸發時，LED1閃爍5次
* 硬體：SW1-3(P0LED)及SW1-4(P1LED)ON，按KEY1(INT0) 
*****************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
main() 
{
  unsigned char i=0; //定義變數=0
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA=1;      //致能整體中斷
  EX0=1;     //致能外部INT0中斷
  IT0=0;	 //0=0準位輸入，1=負緣觸發輸入
  while(1)   //不斷循環，等待INT0外部中斷
   {
     LED0=~i++;  //變數遞加由LED0反相輸出
     Delay_ms(500);//同時等待INT0中斷輸入
   }
}
//********INT0中斷函數，使用暫存器庫1**********
void EX0_int(void) interrupt 0  using 1
 {
    unsigned char i=5;     //定義閃爍5次
    unsigned int  dly; //定義延時變數
    while(i--)  //閃爍次數
     {
      LED1=0x00; dly=50000; while(dly--);//全亮，延時
      LED1=0xff; dly=50000; while(dly--);//全暗，延時
    }
 }
