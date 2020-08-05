// PROGRAM	: U1_4.c							2017.0418
// FUNCTION	: Fast Mode fSYS Switching 			By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	SEGPort		_pg 						//DEFINE 7-SEG PORT
#define	SEGPortC	_pgc 						//DEFINE 7-SEG PORT CONTROL REG
const u8 SEG_TAB[] = {							//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
void Display029(void);
void PAUSE(u8);
void main()
{	u8 i;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	SEGPort=0; SEGPortC=0;						//�M��Port�óW������X�ݩ�
	while(1)
	{ 	for(i=0;i<5;i++)
		{	_scc&=0b00011111;					//scc[7:5]=000,��l�줸��������
			_scc|=(i<<5);						//CKS[2:0]=i,��l�줸��������
			Display029();						//���0��9	
		}
	}	
}
void Display029(void)
{	u8 i;
		for(i=0;i<10;i++)
		{	SEGPort=SEG_TAB[i]; 				//�d������
			PAUSE(10);							//����200000�ӫ��O�P��
		}	
}
void PAUSE(u8 i)					      
{	u8 j;
	i=i>>_scc|(i>>5);
	for (j=0;j<i;j++) GCC_DELAY(20000);			//���� i*20000�ӫ��O�P��
}