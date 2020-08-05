/************** PWM3.C *******PCA計數PWM實習**********
*動作：由接腳CEX0-5(P12~7)輸出6個PWM波形
*硬體：先SW1-4(P1LED)OFF量測電壓，再SW1-4(P1LED)ON觀察LED亮度
****************************************************/
#include "..\MPC82.H" 
void main()
{
	CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
 // CMOD=CPS0; //CPS1-0=01,Fpwm=Fosc/2/256=22.1184MHz/2/256=43.2KHz
	           //致能CEX0-5輸出PWM 
	CCAPM0=CCAPM1=CCAPM2=CCAPM3=CCAPM4=CCAPM5=ECOM+PWM; 
	CCAP0H=0x10;  //設定(P12/CEX0)脈波時間，平均電壓為4.6V
	CCAP1H=0x20;  //設定(P13/CEX1)脈波時間，平均電壓為4.4V
	CCAP2H=0x40;  //設定(P14/CEX2)脈波時間，平均電壓為3.8V
	CCAP3H=0x80;  //設定(P15/CEX3)脈波時間，平均電壓為2.6V
	CCAP4H=0xA0;  //設定(P16/CEX4)脈波時間，平均電壓為1.8V
	CCAP5H=0xFF;  //設定(P17/CEX5)脈波時間，平均電壓為0.01V
	//PCAPWM0=ECAPH; CCAP0H=0x00; //設定(P12/CEX0)，平均電壓為0V

	CR=1;     //開始PCA計數
	while(1); //空轉，此時不斷的由接腳CEX0-5輸出PWM波形
}
