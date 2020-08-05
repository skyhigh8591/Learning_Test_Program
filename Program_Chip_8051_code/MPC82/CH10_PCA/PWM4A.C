/************** PWM4A.C *******ADC與PWM數PWM實習**********
*動作：由ADC控制PWM波形,調整LED亮度音量
*硬體：SW1-4(P1LED)或SW2-6(SPK)ON
*      SW3-1(Ain0)ON，調整Ain0的VR2
*****************************************************/
#include "..\MPC82.H" 
#define  ch     0 //指定由Ain0進行ADC轉換
void main(void)
{
  	P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
	EA=1;              //致能所有中斷
    AUXIE = EADC;      //致能ADC中斷
    ADCTL = ADCON + ADCS + ch; //ADC工作及指定道通進行ADC轉換
	
	CCAPM0=ECOM+PWM; //致能CEX0比較器及PWM輸出 
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //開始PCA計數

	while(1);//空轉，表示此時可做其它工作
}

//**************************************************
void ADC_Interrupt()  interrupt 9 
{ 
   ADCTL=0;    //停止ADC工作
   CCAP0H=ADCH;  //高8-bit數位資料，由PWM輸出
   Delay_ms(10); 
   ADCTL = ADCON + ADCS + ch; //重新啟動ADC
} 