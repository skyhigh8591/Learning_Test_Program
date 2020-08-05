// PROGRAM	: U1_2_4.c								2017.0414
// FUNCTION	: 7 SEGMENT LED Demo Program			By Steven
#include "HT66F2390.h"
#include "MyType.h"
#define SEGPort		_pg
#define SEGPortC	_pgc
void Delay10ms(u8);
const u16 SEG_TAB[] = {		      					//7-Segment Table
			(20<<8)+0x3F,(30<<8)+0x06,(40<<8)+0x5B,	//High-Byte:����`��
			(50<<8)+0x4F,(60<<8)+0x66,(70<<8)+0x6D,	//Low-Byte:�C�q��ܽX
			(80<<8)+0x7D,(90<<8)+0x07,(100<<8)+0x7F,
			(110<<8)+0x67};
void main()
{	s8 i;	
	_wdtc=0xAB;										//�����ݭ̪��p�ɾ�
	SEGPortC=0;										//Config Port as O/P Mode
	while(1)
	{	for(i=9;i>=0;i--)
		{	SEGPort=(u8)SEG_TAB[i];			   		//���oLow-byte�ðe�ܤC�q��ܾ�
			Delay10ms(SEG_TAB[i]>>8);				//����禡
		}
	}
}
void Delay10ms(u8 del)
{	u8 i;											//@fSYS=8MH,����del*10ms
	for(i=0;i<del;i++) GCC_DELAY(20000);
}