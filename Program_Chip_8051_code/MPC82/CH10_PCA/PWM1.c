/********** PWM0.C ******��I/O��XPWM�i��****************
*�ʧ@�G�ѱ��}P12~5��X4��PWM�i��
*�w��G��SW1-4(P1LED)OFF�q���q���A�ASW1-4(P1LED)ON�[��LED�G��
************************************************************/
#include "..\MPC82.H" 
unsigned char PWM_VAR=0;//�ŧiPWM�ܼ�
#define  PWM0_VAR 0x10  //PWM0�]�w��X�ߪi�e��
#define  PWM1_VAR 0x30  //PWM1�]�w��X�ߪi�e��
#define  PWM2_VAR 0x80  //PWM2�]�w��X�ߪi�e��
#define  PWM3_VAR 0xA0  //PWM3�]�w��X�ߪi�e��

sbit PWM0=0x92;  //PWM0=P12
sbit PWM1=0x93;  //PWM1=P13
sbit PWM2=0x94;  //PWM2=P14
sbit PWM3=0x95;  //PWM3=P15

main()
{
  while(1)      //�g���Щl
   {
    PWM0=PWM1=PWM2=PWM3=1;	 //PWM���}�l�Ǧ�=1
    while(PWM_VAR++)	//�YPWM_VAR�����[��0�hPWM��X
	 {
	  if(PWM_VAR > PWM0_VAR) PWM0=0;//�Y�p�ɭ� >PWM0�ȡAPWM0=0
	  if(PWM_VAR > PWM1_VAR) PWM1=0;//�Y�p�ɭ� >PWM1�ȡAPWM1=0
	  if(PWM_VAR > PWM2_VAR) PWM2=0;//�Y�p�ɭ� >PWM2�ȡAPWM2=0
	  if(PWM_VAR > PWM3_VAR) PWM3=0;//�Y�p�ɭ� >PWM3�ȡAPWM3=0
     }	  
   }		 
}