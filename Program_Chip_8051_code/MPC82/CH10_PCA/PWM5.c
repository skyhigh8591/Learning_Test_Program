/********* PWM5.C *******PCA計數PWM直流馬達控制實習**********
*動作：由CEX1(P13)輸出PWM控制直流馬達轉速及P12控制正反轉
*硬體：SW2-7(DIR)及SW2-8(PWM)ON,或SW1-4(P1LED)ON
*****************************************************/
#include "..\MPC82.H" 
sbit DIR=P1^2; //0=馬達正轉,1=馬達反轉
void main()	  
{
    unsigned char i;
    P1M0=0; P1M1=0x06; //設定(P13-2)為推挽式輸出(M0-1=01)
	CCAPM1=ECOM+PWM; //致能CEX1比較器及PWM輸出
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //開始PCA計數
  	DIR=0;	   //0=馬達正轉
	while(1)   //重覆輸出PWM波形
    {
	  for(i=0;i<255;i++)//低電位比率漸漸增加，LED漸亮，馬達加速
	   {
	    CCAP1H=i; //設定CEX1脈波時間
	    Delay_ms(30);
	   }
	  for(i=255;i>0;i--)//低電位比率漸漸減少，LED漸暗，馬達減速
	   {
	    CCAP1H=i; //設定CEX1脈波時間
	    Delay_ms(30);
	   }
	 DIR=!DIR;//切換馬達正/反轉
	}	 
}