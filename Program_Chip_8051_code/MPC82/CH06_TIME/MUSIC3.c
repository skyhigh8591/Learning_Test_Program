/**********MUSIC3.c**** �q�l�^�d��**********
*�ʧ@�G����0~9�A�O��z��X�U�ح��W
*�w��GSW2-5(SPK)ON�A����S1~S10
************************************************/
#include "..\MPC82.H"   //�Ȧs���βպA�w�q
#include "music.h"  //���W�w�q
void dataout(char keyout);    //�����X

unsigned int  code Table[] //���W���C���ơA����0~9�����W  
       = {SI2,DO3,RE3,MI3,FA3,SO3,LA3,SI3,DO4,RE4};
unsigned char   i=0;    //��ƭp��
void main()
{
   unsigned char count=0;  //����p��
   unsigned char scan=0xEF;  //���䱽�y�OROW0=0�A��l��1
   
   TMOD=0x01;   //�]�wTimer0��mode1�����p�� 
   EA=1;ET0=1;  //�P��Timer0���_
 
  while(1)   //���а���
  {
    if(count>15){scan=0xEF;count=0;}//�Y�p��>15�A�q�Y�}�l
    ROW=scan;	  //���y��X
    if(COL0==0) dataout(count);//�ˬdCOL0�C�A�Y�O�p�ƿ�X
    count++; Delay_ms(1);      //�Y���O�A�p��+1
    if(COL1==0) dataout(count);//�ˬdCOL1�C�A�Y�O�p�ƿ�X
    count++; Delay_ms(1);      //�Y���O�A�p��+1
    if(COL2==0) dataout(count);//�ˬdCOL2�C�A�Y�O�p�ƿ�X
    count++; Delay_ms(1);      //�Y���O�A�p��+1
    if(COL3==0) dataout(count);//�ˬdCOL3�C�A�Y�O�p�ƿ�X
    count++; Delay_ms(1);      //�Y���O�A�p��+1
    scan=RL8(scan); //������A�����U�@�C,�OROW0~3���y��0
  }
}
/***********************************************************
*��ƦW��: dataout
*�\��y�z: ����Ū�����W��Ƶo�X�n���A�ˬd�O�_��}����
*��J�ѼơGkeyout
************************************************************/
void dataout(char keyout) 
{	
    i=keyout; //����p�Ʀs�J��ƭp��
	TL0=Table[i];TH0=Table[i] >>8; //�]�w�p�ɭ�     
    TR0=1;             //�Ұ�Timer0�}�l�p��, �o�X�n��
    Delay_ms(1);    	//�B�z������ʤ�����   
    while(!(COL0 & COL1 & COL2 & COL3));//�YCOL0~3��1111����}����
    Delay_ms(1);       	//�B�z������ʤ�����
    TR0=0;              //����Timer0�p�ɡA�����X���W 
}
/***************************************/
void T0_int(void) interrupt 1  //Timer0���_���
{
  TL0=Table[i]; TH0=Table[i] >>8; //���s�]�w�p�ɭ�
  SPEAK=!SPEAK;     //��z�Ϭۿ�X
}

 