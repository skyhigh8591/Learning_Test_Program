/********** CAP1.c ********��������߽d��****************
*�ʧ@�G�OTimer0��T0CKO(P34)��X��i,�e��CEX0(P12)������J
*      �A�bLED��ܮɶ��t
*�w��GSW1-3(P0LED)ON�A�NT0CKO(P34)�s����CEX0(P12)
**********************************************/
#include "..\MPC82.H"  //�Ȧs���βպA�w�q
			     //T0CKO�W�v=Fosc/24/(256-TH0)
#define T  0x14  //T0CKO�W�v=22118400/24/T
main()         
{
  unsigned int first;	//�Ĥ@��CCAP0�����ɶ�
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  AUXR2=T0CKOE; //�P��T0CKO(P34)��X��i
  TMOD=0x02;    //�]�wTimer0��mode2�����p��
  TH0=256-T;    //�N�p�ƭȦs�JTH1
  TR0=1;        //�Ұ�Timer1�A���_����T0CKO(P34)��X��i
  
  CCF0 = 0;		 //�M���Ҳ�0������X��
  CCAPM0 = CAPP+CAPN; //CAPP=1�A���t�έt�tĲ�o��J�ɡACCAP0=(CH:CL)
  CR = 1;        //�Ұ�PCA�p�� 
  while(1)
   {
	 CL = CH =0;     //PCA�p�ƾ���0�}�l�W��
	 while(CCF0==0); //���ݲĤ@��Ĳ�o��J
	 CCF0 = 0;		 //�M��PCA�Ҳ�0���X��
	 first=CCAP0L ;  //����CPA�p�ƭ�
	
	 while(CCF0==0); //���ݲĤG��Ĳ�o��J
 	 CCF0 = 0;		 //�M��PCA�Ҳ�0���X��
	 LED=~(CCAP0L-first) ;//�N�⦸CPA�p�ƭȪ��ɶ��t(T)��LED��X
   }	
}
