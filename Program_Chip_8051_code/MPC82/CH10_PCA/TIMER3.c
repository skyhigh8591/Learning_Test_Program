/******TIMER3.C******PCA�n��p�ɤ��_�d�� ************
*�\��J�ϥ�PCA�n��p�ɤ��_�A����6��LED����A���j0.5��
*�w��GSW1-3(P0LED)ON
****************************************************/
#include "..\MPC82.H" //�Ȧs���βպA�w�q
//Fosc=22.1184MHz�APCA�p�Ʈɯ�=Fosc/12=1.8432MHz
#define T  7200 //�n��p�ɮɶ�=(1/1.8432MHz)*7200=3906.25uS
main()         
{ P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  PCON2=7;  //Fosc=Fosc/128�A�n��p�ɮɶ�=3906.25uS*128=0.5��
  CMOD = 0; //PCA�p�Ʈɯߨӷ�CPS1-0:00=Fosc/12
  CCAPM0=CCAPM1=CCAPM2=CCAPM3=CCAPM4=CCAPM5=ECOM+MAT+ECCF; 
                   //MAT=1�APAC�p�ƻPCCAP0�ǰt�ɡA�OCCF0=1
                   //ECOM=1�A�P�������\��
			       //ECCF=1�A�P�঳�ǰt(CCFn=1)�ɡA���ͤ��_
  CCAP0L=T;   CCAP0H=T>>8;     //�]�w�Ҳ�0����Ȧs��=0.5��
  CCAP1L=T*2; CCAP1H=(T*2)>>8; //�]�w�Ҳ�1����Ȧs��=1��
  CCAP2L=T*3; CCAP2H=(T*3)>>8; //�]�w�Ҳ�2����Ȧs��=1.5��
  CCAP3L=T*4; CCAP3H=(T*4)>>8; //�]�w�Ҳ�3����Ȧs��=2��
  CCAP4L=T*5; CCAP4H=(T*5)>>8; //�]�w�Ҳ�4����Ȧs��=2.5��
  CCAP5L=T*6; CCAP5H=(T*6)>>8; //�]�w�Ҳ�5����Ȧs��=3��

  EA = 1;            //�P��Ҧ����_
  AUXIE = EPCA;      //�P��PCA���_
  CCF0=CCF1=CCF2=CCF3=CCF4=CCF5=0;  //�M���Ҳ�0-5������X��
  LED = 0xFF;
  CR = 1;            //�Ұ�PCA�p�� 
  while(1);	         //����,����(CH:CL)=CCAP0���ͤ��_
 }
/***********************************************************
*��ƦW��: PCA���_���
*�\��y�z: ����6��LED����
************************************************************/
void PCA_Interrupt() interrupt 10
{ if(CCF0) LED = 0xFE;    //��0.5��ʧ@
  if(CCF1) LED = RL8(LED);//��1��ʧ@
  if(CCF2) LED = RL8(LED);//��1.5��ʧ@
  if(CCF3) LED = RL8(LED);//��2��ʧ@
  if(CCF4) LED = RL8(LED);//��2.5��ʧ@
  if(CCF5){LED=RL8(LED);CL=CH=0;}//��3��ʧ@�APCA�p�ƾ���0�W��	
  CCF0=CCF1=CCF2=CCF3=CCF4=CCF5=0; //�M���Ҳ�0-5������X��     
}
