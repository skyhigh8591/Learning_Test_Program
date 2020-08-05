// PROGRAM	: U2_2_2.c							2017.0424
// FUNCTION	: WDT with RES Pin Reset 			By Steven
#include <HT66F2390.h>
#include "MyType.h"
#define SEGPort  	_pg
#define SEGPortC 	_pgc
const u8 SEG_TAB[] = {							//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
void Delayms(u16 del);
void main()
{	u8 i;	
	_wdtc=0b01010110;							//�P��ݭ̪��p�ɾ�,Time-out=2^17/fS
	SEGPort=0; SEGPortC=0;						//�W��SEGPort����X�ݩʨÿ�X0
	_rstc=0xAA;									//�P��RES�}�쭫�m�\��
	if(_to)										//�O�_��WDT Time-out���m
	{	for(i=0;i<10;i++)						//�O,�{�{a��g�`�q
		{	SEGPort^=0xFF;
			Delayms(100);						//����0.1S
		}
	}
	for(i=0;i<10;i++)
	{	SEGPort=SEG_TAB[i]; Delayms(250);		//���i�Ȩé���0.25S
	} 
	SEGPort=0;									//�����C�q��ܾ�
	while(1);									//�L�a�j��(����MCU���)
}
void Delayms(u16 del)
{	u16 i;										//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
	GCC_CLRWDT();								//�M��WDT
}