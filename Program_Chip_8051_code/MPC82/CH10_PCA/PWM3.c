/************** PWM3.C *******PCA�p��PWM���**********
*�ʧ@�G�ѱ��}CEX0-5(P12~7)��X6��PWM�i��
*�w��G��SW1-4(P1LED)OFF�q���q���A�ASW1-4(P1LED)ON�[��LED�G��
****************************************************/
#include "..\MPC82.H" 
void main()
{
	CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
 // CMOD=CPS0; //CPS1-0=01,Fpwm=Fosc/2/256=22.1184MHz/2/256=43.2KHz
	           //�P��CEX0-5��XPWM 
	CCAPM0=CCAPM1=CCAPM2=CCAPM3=CCAPM4=CCAPM5=ECOM+PWM; 
	CCAP0H=0x10;  //�]�w(P12/CEX0)�ߪi�ɶ��A�����q����4.6V
	CCAP1H=0x20;  //�]�w(P13/CEX1)�ߪi�ɶ��A�����q����4.4V
	CCAP2H=0x40;  //�]�w(P14/CEX2)�ߪi�ɶ��A�����q����3.8V
	CCAP3H=0x80;  //�]�w(P15/CEX3)�ߪi�ɶ��A�����q����2.6V
	CCAP4H=0xA0;  //�]�w(P16/CEX4)�ߪi�ɶ��A�����q����1.8V
	CCAP5H=0xFF;  //�]�w(P17/CEX5)�ߪi�ɶ��A�����q����0.01V
	//PCAPWM0=ECAPH; CCAP0H=0x00; //�]�w(P12/CEX0)�A�����q����0V

	CR=1;     //�}�lPCA�p��
	while(1); //����A���ɤ��_���ѱ��}CEX0-5��XPWM�i��
}
