/*** TIMER1.C*********PCA�n��p�ɾ��d��************
*�ʧ@�GPCA�n��p�ɾ����ɡA����LED�C��Ϭۤ@���C
*�w��GSW1-3(P0LED)ON
***********************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
//Fosc=22.1184MHz�APCA�p�Ʈɯ�=Fosc/12=1.8432MHz
#define T  14400  //�n��p�ɮɶ�=(1/1.8432MHz)*14400=7812.5uS
main()         
{
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  PCON2=7; //Fosc=Fosc/128�A�n��p�ɮɶ�=7812.5uS*128=1��
  CMOD=0;  //PCA�p�Ʈɯߨӷ�CPS1-0:00=Fosc/12
  CCAPM0 = ECOM+MAT; //MAT=1�APAC�p�ƻPCCAP0�ǰt�ɡA�OCCF0=1
                     //ECOM=1�A�P�������\��

  CCAP0L=T;	    //�]�w����Ȧs���C�줸��
  CCAP0H=T>>8;  //�]�w����Ȧs�����줸��
  CR=1;         //�Ұ�PCA�p��    
  while(1)
   {
	 CCF0 = 0;		//�M���Ҳ�0������X��
	 CL = CH =0;    //PCA�p�ƾ���0�}�l�W��
	 while(CCF0==0);//����PCA�p�ƾ�(CH:CL)=CCAP0�A�O���_�X��CCF0=1
	 P0_0=!P0_0;	//LED�Ϭ۰{�{
   }	
}
