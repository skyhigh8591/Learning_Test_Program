/******** KEY5.C******4*4�~�����_��߽d��***************
*�ʧ@�GROW0~3���y��X,COL0~3�����J,�bLED��X
*�w��GSW1-3(P0LED)�u���AJ15(INT0)�u���A��S1~S16 
***********************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
unsigned char count=0;  //���=0
void main()
{
 unsigned char scan=0xEF;  //���䱽�y�OROW0=0�A��l��1
 P0M0=0; P0M1=0xFF; //�]�wP0����������X(M0-1=01)
 EA=1; EX0=1;    //�P��~�����_
 LED=~count;    //��l���0
 while(1)       //���а���
  {
    if(count>15){scan=0xEF;count=0;}//�Y���>15,�q�Y���y
    ROW=scan;		  //���y��X
    Delay_ms(1);   
    scan=RL8(scan); //������A�����U�@�C,�OROW0~3���y��0
    count=count+4;	//���+4
  }
}
 //***********************************************
void INT0_Interrupt() interrupt 0   //INT0���_���	
{ 
   unsigned int dly;
   unsigned char key;	 //�ŧi����p��
   key=count;	         //��Ʀs�J����p�Ƥ�
   if(COL0==0) LED=~key; //�ˬdCOL0�C�A�Y������p�ƿ�X
   key++;                //�Y���O����p�ƻ��[  
   if(COL1==0) LED=~key; //�ˬdCOL1�C�A�Y������p�ƿ�X
   key++;                //�Y���O����p�ƻ��[
   if(COL2==0) LED=~key; //�ˬdCOL2�C�A�Y������p�ƿ�X
   key++;                //�Y���O����p�ƻ��[
   if(COL3==0) LED=~key; //�ˬdCOL3�C�A�Y������p�ƿ�X

   dly=1200;  while(dly--);//�B�z������ʤ�����   
   while(!(COL0 & COL1 & COL2 & COL3));//�YCOL0~3��1111����}����
   dly=1200;  while(dly--);//�B�z������ʤ�����	    
   }
