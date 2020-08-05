/********* PWM5.C *******PCA�p��PWM���y���F������**********
*�ʧ@�G��CEX1(P13)��XPWM����y���F��t��P12�������
*�w��GSW2-7(DIR)��SW2-8(PWM)ON,��SW1-4(P1LED)ON
*****************************************************/
#include "..\MPC82.H" 
sbit DIR=P1^2; //0=���F����,1=���F����
void main()	  
{
    unsigned char i;
    P1M0=0; P1M1=0x06; //�]�w(P13-2)����������X(M0-1=01)
	CCAPM1=ECOM+PWM; //�P��CEX1�������PWM��X
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //�}�lPCA�p��
  	DIR=0;	   //0=���F����
	while(1)   //���п�XPWM�i��
    {
	  for(i=0;i<255;i++)//�C�q���v�����W�[�ALED���G�A���F�[�t
	   {
	    CCAP1H=i; //�]�wCEX1�ߪi�ɶ�
	    Delay_ms(30);
	   }
	  for(i=255;i>0;i--)//�C�q���v������֡ALED���t�A���F��t
	   {
	    CCAP1H=i; //�]�wCEX1�ߪi�ɶ�
	    Delay_ms(30);
	   }
	 DIR=!DIR;//�������F��/����
	}	 
}