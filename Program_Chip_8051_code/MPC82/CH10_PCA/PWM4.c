/************** PWM4.C *******PCA計數PWM實習**********
*動作：不斷改變CEX0(P12)輸出的PWM波形,調整LED亮度或喇叭音量
*硬體：SW1-4(P1LED)或SW2-6(SPK)ON
*****************************************************/
#include "..\MPC82.H" 
void main()	  
{
    unsigned char i;
	CCAPM0=ECOM+PWM; //致能CEX0比較器及PWM輸出 
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //開始PCA計數
    while(1)   //重覆輸出PWM波形
    {
	  for(i=0;i<255;i++)//低電位比率漸漸增加，LED漸亮
	   {
	    CCAP0H=i; //設定CEX0的PWM脈波時間
	    Delay_ms(30);
	   }
	  for(i=255;i>1;i--)//低電位比率漸漸減少，LED漸暗
	   {
	    CCAP0H=i; //設定CEX0的PWM脈波時間
	    Delay_ms(30);
	   }
	}	 
}