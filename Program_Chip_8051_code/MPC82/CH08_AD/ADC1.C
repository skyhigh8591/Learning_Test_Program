/************** ADC1.C *******ADC實習範例**********
*動作：輸入類比電壓，讀取高8-bit數位資料，由LED顯示
*硬體：SW1-3(P0LED) ON, SW3-1(Ain0) ON，調整Ain0的VR2
****************************************************/
#include "..\MPC82.H"
#define  ch     0 //指定由Ain0進行ADC轉換
void main(void)
{
 P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
 while(1)
  {
    ADCTL =ADCON + ADCS + ch; //ADC工作及指定道通進行ADC轉換
    while(!(ADCTL & ADCI));   //檢查ADCI是否轉換完畢
    ADCTL=0;                  //轉換完畢，停止ADC工作
    LED=~ADCH;		          //高8-bit數位資料，由LED顯示
	Delay_ms(100);
  }
}