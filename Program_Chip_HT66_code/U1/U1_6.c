// PROGRAM	: U1_6.c								2017.0418
// FUNCTION	: 4X4 MATRIX KEYPAD DEMO PROGRAM		By Steven
#include <HT66F2390.h>
#include "MyType.h"
#define		SEGPort		_pg
#define		SEGPortC	_pgc
#define 	KeyPort		_pc			
#define 	KeyPortC	_pcc
#define 	KeyPortPU	_pcpu
const u8 SEG_TAB[] = {0x3F,0x06,					//7-Segment Table(0~F)
			0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,
			0x67,0x77,0x7C,0x58,0x5E,0x79,0x71};
u8 ScanKey(void);
void main()
{	u8 i,Key;
	_wdtc=0b10101111;								//�����ݭ̪��p�ɾ�
	SEGPort=0; SEGPortC=0;							//�M��Port�óW������X�ݩ�
	while(1)
	{	SEGPort=1<<7;								//�I�G�C�q��ܾ�h�`�q�A��l�`�q����
		do
		{ 	Key=ScanKey();
			GCC_DELAY(200000);  					//���� 100ms
			SEGPort^=(1<<7);						//�C�q��ܾ�h�`�q�G������
		} while(Key==16);	   						//���ݫ�������
		SEGPort=SEG_TAB[Key];				      	//�d�����ܫ����
		for(i=0;i<10;i++) GCC_DELAY(200000);  		//���� 1 Sec
	}	
}
u8 ScanKey()
{	u8 i,key=0;
	KeyPortC=0xF0; KeyPortPU=0xF0;			   		//�W��KeyPort[7:4]/[3:0]����J/��X�ݩʡA�íP��KeyPort[7:4]���ɹq��
	KeyPort=0b11111110;					         	//�e�X���y�XKeyPort[3:0]=1110
	for(i=0;i<=3;i++)								//�̧��ˬd�|�C
	{	if(!(KeyPort & 1<<7)) break;		      	//�ˬd��0��(KeyPort[4])�O�_���U
		key++;										//�_�A�����+1
		if(!(KeyPort & 1<<6)) break;			   	//�ˬd��1��(KeyPort[5])�O�_���U
		key++;										//�_�A�����+1
		if(!(KeyPort & 1<<5)) break;			   	//�ˬd��2��(KeyPort[6])�O�_���U
		key++;										//�_�A�����+1
		if(!(KeyPort & 1<<4)) break;			   	//�ˬd��3��(KeyPort[7])�O�_���U
		key++;										//�_�A�����+1
		KeyPort<<=1; KeyPort|=0b00000001;	   		//��s���y�X�A�ýT�OKeyPort[3:0]�u���@�Ӧ줸��0
	}
	return key;	
}