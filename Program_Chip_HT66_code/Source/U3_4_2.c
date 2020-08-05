// PROGRAM	: U3_4_2.c						2017.0427
// FUNCTION	: CP1 Control with Calibration	By Steven
#include <HT66F2390.h>
#include "MyType.h"			
#define LEDPort		_pf
#define LEDPortC	_pfc
void CP1Calibration(void);
void main()
{	_wdtc=0b10101111;						//�����ݭ̪��p�ɾ�
	LEDPort=0xFF; LEDPortC=0;				//�W��LEDPort����X�ݩʨÿ�XFF
	_pds1=0x3F;								//PD6=>C1x, PD5=>C1+,PD4=>C1-
	_cp1c=0b01000000;						//�P��CP1,C1POL=0, �T���ɶ��̺C
	CP1Calibration();						//�i��CP1��J�����q���ե��{��
	_cp1e=1; _emi=1;						//�P��CP1���_�P���_�`�}��
	while(1);								//�L�a�j��
}
void CP1Calibration(void)
{	volatile u8 i,cout,VCOS1,VCOS2;
	_cp1vos=0b01000000;						//C10FM=1(�ե��Ҧ�),C1RSP=0(C1-���Ѧҿ�J)
	GCC_DELAY(90); cout=_c1out;				//���ݤ������Xí�w, ���oC1OUT
	for(i=0;i<31;i++)
	{	_cp1vos++; GCC_DELAY(90);			//C1OF[4:0]+1, ���ݤ������Xí�w
		if(cout!=_c1out) break;				//�YC1OUT����,�����j��	
	}
	VCOS1=_cp1vos & 0x1F;					//VCOS1=C1OF[4:0]
	_cp1vos=0b01011111;						//C1OF[4:0]=11111b
	GCC_DELAY(90); cout=_c1out;				//���ݤ������Xí�w, ���oC1OUT
	for(i=0;i<31;i++)
	{	_cp1vos--; GCC_DELAY(90);			//C1OF[4:0]-1, ���ݤ������Xí�w
		if(cout!=_c1out) break;				//�YC1OUT����,�����j��
	}
	VCOS2=(_cp1vos & 0x1F);					//VCOS2=C1OF[4:0]
	_cp1vos=(VCOS1+VCOS2)>>1; 				//C1OF[4:0]=(VCOS1+VCOS2)/2,C10FM=0
}
DEFINE_ISR(ISR_CP1,0x10)					//CP1 Interrupt Vector
{	u8 i;	
	if(_c1out)								//C1+ > C1- ?
	{	for(i=0;i<8;i++) 					//�L�Ϯg�H��LEDs�v�@����
		{	LEDPort>>=1; LEDPort|=(1<<7);	//�k���@���ó]�mMSB=1 
			GCC_DELAY(160000);				//����80ms
		}
 	}
	else									//C1+ < C1-
	{ 	for(i=0;i<8;i++) 					//���Ϯg�H��LEDs�v�@�I�G					
		{	LEDPort<<=1; 					//�����@��
			GCC_DELAY(160000);				//����80ms
		}
	}
}