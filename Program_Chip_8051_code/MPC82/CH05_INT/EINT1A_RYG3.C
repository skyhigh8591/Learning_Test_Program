/********** EINT1.c ********外部中斷範例***************
* 動作：LED0遞加，INT0腳輸入0準位或負緣觸發時，LED1閃爍5次
* 硬體：SW1-3(P0LED)及SW1-4(P1LED)ON，按KEY1(INT0) 
*****************************************************/
#include "..\MPC82.H"   //暫存器及組態定義
char code light[]=   //紅黃綠燈的變化資料
{0x21,0x01,0x21,0x01,0x21,0x01,0x21,0x11,
 0x0C,0x08,0x0C,0x08,0x0C,0x08,0x0C,0x0A};

char code time[] =   //每一個變化的時間
{30,1,1,1,1,1,1,4,30,1,1,1,1,1,1,4};

main() 
{
  unsigned char i=0; //定義變數=0
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  EA=1;      //致能整體中斷
  EX0=1;     //致能外部INT0中斷
  IT0=0;	 //0=0準位輸入，1=負緣觸發輸入
  while(1)   //不斷循環，等待INT0外部中斷
   {
      for (i=0;i<16;i++) //設定0~15個變化
      {
        if(KEY1==0) break;//若當KEY1=0時，跳出迴圈，黃燈互閃
        LED=light[i];  //紅黃綠燈資料反相輸出
        Delay_ms(time[i]*100);//將每一個變化的時間送到延時函數
      }
   }
}
//********INT0中斷函數，使用暫存器庫1**********
void EX0_int(void) interrupt 0  using 1
 {
     unsigned int  dly; //定義延時變數
	 char i=5;
    while(i--)  //閃爍次數
     {
       LED=~0x10;  dly=50000;  while(dly--);    //黃燈互閃
       LED=~0x02;  dly=50000;  while(dly--); 
    }	
}
