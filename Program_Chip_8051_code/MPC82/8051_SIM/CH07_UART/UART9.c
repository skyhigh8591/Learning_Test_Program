/********** UART9.c ****************************
*�ʧ@�G�OUART2�j�v���;���S2CKO(P35)��X��i
*�w��GS2CKO(P35)�}�s��P10�A�C�WSW1-4(P1LED)ON�A���WSW2-5(SPK)ON
**********************************************/
#include "..\MPC82.H"  //�Ȧs���βպA�w�q
			    //S2CKO�W�v=Fosc/24/(256-S2BRT)
#define T  225  //S2CKO�W�v=22118400/24/225=4096Hz
main()         
{
  PCON2=7;	     //Fosc=Fosc/128�AS2CKO�W�v=4096Hz/128=32Hz
  S2BRT=256-T;       //�N�p�ƭȦs�JS2BRT
  AUXR2=S2CKOE+S2TR; //�P��S2CKO(P35)��X��i�A�Ұ��j�v���;�
  while (1);    //���_�`������
}
