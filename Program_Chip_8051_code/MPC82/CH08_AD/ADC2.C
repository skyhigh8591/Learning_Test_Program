/************** ADC2.C *******ADC中斷實習範例**********
*動作：輸入類比電壓，以中斷方式讀取高8-bit數位資料，由LED顯示
*硬體：SW1-3(P0LED) ON, SW3-1(Ain0) ON，調整Ain0的VR2
****************************************************/
#include "..\MPC82.H"
#define  ch     0 //指定由Ain0進行ADC轉換
void main(void)
{
  	P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
	EA=1;              //致能所有中斷
    AUXIE = EADC;      //致能ADC中斷
    ADCTL = ADCON + ADCS + ch; //ADC工作及指定道通進行ADC轉換
	while(1);//空轉，表示此時可做其它工作
}
//**************************************************
void ADC_Interrupt()  interrupt 9 
{ 
   ADCTL=0;    //停止ADC工作
   LED=~ADCH;  //高8-bit數位資料，由LED顯示
   ADCTL = ADCON + ADCS + ch; //重新啟動ADC
}
