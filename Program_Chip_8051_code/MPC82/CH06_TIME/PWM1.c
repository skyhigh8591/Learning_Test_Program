/********** PWM1.C ***********************
*�ʧ@�G�ϥΰ�I/O��X4�Ӫ�PWM�i�� 
*****************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
unsigned char PWM_VAR=0;      //�w�qPWM�ƭ��ܼ�
unsigned char PWM1_VAR=0x10;  //�w�qPWM1�}��X�ߪi
unsigned char PWM2_VAR=0x80;  //�w�qPWM2�}��X�ߪi
unsigned char PWM3_VAR=0xA0;  //�w�qPWM3�}��X�ߪi
unsigned char PWM4_VAR=0xF0;  //�w�qPWM4�}��X�ߪi
unsigned char PWM5_VAR=0x10;  //�w�qPWM5�}��X�ߪi
unsigned char PWM6_VAR=0x80;  //�w�qPWM6�}��X�ߪi
unsigned char PWM7_VAR=0xA0;  //�w�qPWM7�}��X�ߪi
unsigned char PWM8_VAR=0xF0;  //�w�qPWM8�}��X�ߪi

sbit PWM1=0x80;  //PWM1=P00
sbit PWM2=0x81;  //PWM2=P01
sbit PWM3=0x82;  //PWM3=P02
sbit PWM4=0x83;  //PWM4=P03
sbit PWM5=0x84;  //PWM5=P04
sbit PWM6=0x85;  //PWM6=P05
sbit PWM7=0x86;  //PWM7=P06
sbit PWM8=0x87;  //PWM8=P07

main()
{
  while(1)      //�g���Щl
   {
    PWM1=PWM2=PWM3=PWM4=1;	 //PWM���}�l�Ǧ�=1
    while(PWM_VAR++)	//�YPWM_VAR�����[��0�hPWM��X
	 {
	  if(PWM_VAR > PWM1_VAR) PWM1=0;//�Y�p�ɭ� >PWM1�ȡAPWM1=0
	  if(PWM_VAR > PWM2_VAR) PWM2=0;//�Y�p�ɭ� >PWM2�ȡAPWM2=0
	  if(PWM_VAR > PWM3_VAR) PWM3=0;//�Y�p�ɭ� >PWM3�ȡAPWM3=0
	  if(PWM_VAR > PWM4_VAR) PWM4=0;//�Y�p�ɭ� >PWM4�ȡAPWM4=0
		if(PWM_VAR > PWM1_VAR) PWM5=0;//�Y�p�ɭ� >PWM5�ȡAPWM5=0
	  if(PWM_VAR > PWM2_VAR) PWM6=0;//�Y�p�ɭ� >PWM6�ȡAPWM6=0
	  if(PWM_VAR > PWM3_VAR) PWM7=0;//�Y�p�ɭ� >PWM7�ȡAPWM7=0
	  if(PWM_VAR > PWM4_VAR) PWM8=0;//�Y�p�ɭ� >PWM8�ȡAPWM8=0
     }	  
   }
}