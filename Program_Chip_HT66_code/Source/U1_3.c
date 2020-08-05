// PROGRAM	: U1_3.c								2017.0418
// FUNCTION	: HIRC Frequency Control Demo Program	By Steven
#include <HT66F2390.h>
#include "MyType.h"
#define SEGPort		_pg
#define SEGPortC	_pgc
void Delayms(u16);
const u8 SEG_TAB[] = {		      					//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
void main()
{	u8 i;	
	_wdtc=0xAB;										//�����ݭ̪��p�ɾ�
	SEGPortC=0;										//Config Port as O/P Mode
	while(1)
	{	for(i=0;i<10;i++)
		{	SEGPort=SEG_TAB[i];			   			//���o��ܽX�ðe�ܤC�q��ܾ�
			Delayms(600);							//����禡
		}
//		_hircc^=0x08;								//8M/16M HIRC�W�v����
//		while(!_hircf);								//����HIRC�W�ví�w
	}
}
void Delayms(u16 del)
{	u16 i;											//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}