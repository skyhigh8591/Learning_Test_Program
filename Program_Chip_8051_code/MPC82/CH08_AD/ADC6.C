/************** ADC6.C *******ADC定時中斷實習範例**********
*動作：輸入類比電壓，以定時中斷方式讀取高8-bit數位資料，由LED顯示
*硬體：SW1-3(P0LED) ON, SW3-1(Ain0) ON，調整Ain0的VR2
****************************************************/
#include "..\MPC82.H"
#define  ch     0 //指定由Ain0進行ADC轉換
#define T  2000*221184/240000  //Timer延時時間=1mS
main()         
{
  P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
  TMOD = 0x01; /*0000 0001，設定Timer0為mode1內部計時
                 bit3:GATE=0,不使用外部INT0接腳
  		         bit2:C/T0=0,內部計時 
			     bit1-0:MODE=01,使用模式1工作*/
  TL0=65536-T; TH0=(65536-T)>>8; //設定Timer0計數值
  EA=1;ET0=1;    //致能Timer0中斷
  TR0=1;         //啟動Timer0開始計時
  while(1);//空轉，表示此時可做其它工作
}
/************************************************************/
void T0_int(void) interrupt 1  //Timer0中斷函數
  {
    TL0=65536-T; TH0=(65536-T)>>8; //重新設定Timer0計數值
	ADCTL = ADCON + ADCS + ch; //重新啟動ADC
    while(!(ADCTL & ADCI));   //檢查ADCI是否轉換完畢
	ADCTL=0;    //停止ADC工作
    LED=~ADCH;  //高8-bit數位資料，由LED顯示
  }
