/********** CAP2.c ********��������߽d��****************
*�ʧ@�G�OTimer2��T2CKO(P10)��X��i,�e��CEX0(P12)������J
*      �A�bLED��ܮɶ��t
*�w��GSW1-3(P0LED)ON�A�NT2CKO(P10)�s����CEX0(P12)
**********************************************/
#include "..\MPC82.H"  //�Ȧs���βպA�w�q
#define T 0x56 //T2CKO�W�v=Fosc/4/(65536-T2)=22118400/4/T			    
main()          
{
  unsigned int first,i;	//�Ĥ@��CCAP0�����ɶ�
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  T2CON=0x00; /* 0000 0000�A�]�w�������p�ɡA���쭫�s���J
                 bit3:EXEN2=0,���ϥΥ~��T2EX���}
			     bit1:C/T2=0,�����p�� */
  RCAP2=T2R=65536-T; //�]�wTimer2�έ��s���J�ɶ�
  TR2=1;        //�Ұ�Timer2�}�l�p��
  T2MOD=T2CKOE; //�P��T2CKO(P10)��X��i
  
  CCF0 = 0;		 //�M���Ҳ�0������X��
  CMOD = CPS0;//PCA�ɯߨӷ�:CPS1-0:01=Fosc/2,�t�XT2CKO=Fosc/4/(65536-T2)
  CCAPM0 = CAPP+CAPN; //CAPP=1�A���t�έt�tĲ�o��J�ɡACCAP0<--CH:CL)
  CR = 1;        //�Ұ�PCA�p�� 
  while(1)
   {
	 CL = CH =0;     //PCA�p�ƾ���0�}�l�W��
	 while(CCF0==0); //���ݲĤ@��Ĳ�o��J
	 CCF0 = 0;		 //�M���Ҳ�0���X��
	 first=CCAP0L ;  //����CPA�p�ƭ�
	
	 while(CCF0==0); //���ݲĤG��Ĳ�o��J
 	 CCF0 = 0;		 //�M���Ҳ�0���X��
	 i=CCAP0L-first ;  //����CPA�p�ƭ�
	 LED=~i ;//�N�⦸CPA�p�ƭȪ��ɶ��t(T)��LED��X
   }	
}
