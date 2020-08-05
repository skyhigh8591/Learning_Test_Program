/************** PWM4B.C *******ADC與PWM數PWM實習**********
*動作：由ADC控制PWM波形,調整LED亮度音量
*硬體：SW1-4(P1LED)或SW2-6(SPK)ON，
*      SW3-1~2(Ain0~1)ON，調整Ain0~1的VR2~3
*****************************************************/
#include "..\MPC82.H" 
bit ch=0;						 //類比通道
void main(void)
{
  	P0M0=0; P0M1=0xFF; //設定P0為推挽式輸出(M0-1=01)
	EA=1;              //致能所有中斷
    AUXIE = EADC;      //致能ADC中斷
    ADCTL=ADCON + ADCS + 0 ; //由Ain0進行ADC轉換
	
	CCAPM1=CCAPM0=ECOM+PWM; //致能CEX1-0比較器及PWM輸出 
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //開始PCA計數

	while(1);//空轉，表示此時可做其它工作
}

//**************************************************
void ADC_Interrupt()  interrupt 9 
{ 
   if(ch==0)  //若是Ain0類比輸入
    {
	  ADCTL= 1;    //改為Ain1，停止ADC工作
      CCAP0H=ADCH;  //高8-bit數位資料，由PWM0輸出
	}
   else	//若是Ain1類比輸入
      {
		ADCTL= 0;     //改為Ain0，停止ADC工作
        CCAP1H=ADCH;  //高8-bit數位資料，由PWM1輸出
	   }
    ch=!ch;  //換另一通道
	Delay_ms(10);
    ADCTL=ADCTL+ADCON + ADCS; //重新啟動ADC轉換
} 