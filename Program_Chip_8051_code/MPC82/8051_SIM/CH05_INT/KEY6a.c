/***** KEY6A.C******4*4���y���䤤�_(KBI)��߽d��***************
*�ʧ@�GROW0~3���y��X,COL0~3�����J,�bLED��X
*�w��GSW1-3(P0LED)�u���A��S1~S16 
**********************************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
unsigned char count=0;  //���=0
void main()
{
  unsigned char scan=0xEF;  //���䱽�y�OROW0=0�A��l��1
  P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
  EA = 1;            //�P��Ҧ����_
  AUXIE = EKBI;      //�P��KBI���_
  KBMASK = 0x0F ;    //���P23-0�����䤤�_
  LED1=~count;       //��l���0
  ROW=0x0F;          //���y��X=0000
  while(1);          //���ݫ���A���ɥi���䥦�u�@
}
 //***********************************************
void KBI_Interrupt() interrupt 13   //Keypad���_���	
{ 
  unsigned char key=0;	    //�ŧi����p��
  unsigned char scan=0xEF;  //���䱽�y�OROW0=0�A��l��1
  while(1)
   {
     ROW=scan;		  //���y��X
	 if(!(COL0 & COL1 & COL2 & COL3)) break;//�YCOL0~3�䤤���@��0�A�h�X��� 
     scan=RL8(scan); //������A�����U�@�C,�OROW0~3���y��0
     key=key+4;	//���+4
   }
  if(COL0==0) LED=~key; //�ˬdCOL0�C�A�Y������p�ƿ�X
  key++;                //�Y���O����p�ƻ��[  
  if(COL1==0) LED=~key; //�ˬdCOL1�C�A�Y������p�ƿ�X
  key++;                //�Y���O����p�ƻ��[
  if(COL2==0) LED=~key; //�ˬdCOL2�C�A�Y������p�ƿ�X
  key++;                //�Y���O����p�ƻ��[
  if(COL3==0) LED=~key; //�ˬdCOL3�C�A�Y������p�ƿ�X

  Delay_ms(1);//�B�z������ʤ�����   
  while(!(COL0 & COL1 & COL2 & COL3));//�YCOL0~3��1111����}����
  Delay_ms(1);//�B�z������ʤ�����	    
  KBCON &= ~KBIF;  //�M�����䤤�_�X��KBIF=0
  ROW=0x0F;   //���y��X=0000    
}
