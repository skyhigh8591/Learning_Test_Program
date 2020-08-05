// PROGRAM	: U3_4_1.c						2017.0427
// FUNCTION	: CP1 Control Demo Program    	By Steven
#include <HT66F2390.h>
#include "MyType.h"			
#define LEDPort		_pf
#define LEDPortC	_pfc
void main()
{	_wdtc=0b10101111;						//�����ݭ̪��p�ɾ�
	LEDPort=0xFF; LEDPortC=0;				//�W��LEDPort����X�ݩʨÿ�XFF
	_pds1=0x3F;								//PD6=>C1x, PD5=>C1+,PD4=>C1-
	_cp1c=0b01000000;						//�P��CP1,C1POL=0
	_cp1e=1; _emi=1;						//�P��CP1���_�P���_�`�}��
	while(1);								//�L�a�j��
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