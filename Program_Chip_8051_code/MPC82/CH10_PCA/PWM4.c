/************** PWM4.C *******PCA�p��PWM���**********
*�ʧ@�G���_����CEX0(P12)��X��PWM�i��,�վ�LED�G�שγ�z���q
*�w��GSW1-4(P1LED)��SW2-6(SPK)ON
*****************************************************/
#include "..\MPC82.H" 
void main()	  
{
    unsigned char i;
	CCAPM0=ECOM+PWM; //�P��CEX0�������PWM��X 
    CMOD=0x00; //CPS1-0=00,Fpwm=Fosc/12/256=22.1184MHz/12/256=7.2KHz
	CR=1;      //�}�lPCA�p��
    while(1)   //���п�XPWM�i��
    {
	  for(i=0;i<255;i++)//�C�q���v�����W�[�ALED���G
	   {
	    CCAP0H=i; //�]�wCEX0��PWM�ߪi�ɶ�
	    Delay_ms(30);
	   }
	  for(i=255;i>1;i--)//�C�q���v������֡ALED���t
	   {
	    CCAP0H=i; //�]�wCEX0��PWM�ߪi�ɶ�
	    Delay_ms(30);
	   }
	}	 
}