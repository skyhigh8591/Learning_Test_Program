// PROGRAM	: U3_3_1.c							2017.0427
// FUNCTION	: ADC with Multi 7-SEGMENT Display	By Steven
#include <HT66F2390.h>
#include "MyType.h"
#define	 SEGPort	_pg
#define  SEGPortC	_pgc
#define	 ScanPort	_pe
#define	 ScanPortC	_pec
const u8 SEG_TAB[] = {			   				//�C�q��ܽX�ت��(�@��)
				0x3F,0x06,0x5B,0x4F,0x66,
			   	0x6D,0x7D,0x07,0x7F,0x67};
volatile u8 *ptr,ScanCode,Buffer[4];
void main()
{	u8 i; u16 adr;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	SEGPort=0; SEGPortC=0;						//�W��SEGPort����X�ݩ�
	ScanPort&=0xF0; ScanPortC&=0xF0;			//�W��ScanPort[3:0]����X�ݩ�
	_psc0r=0x01; _tb0c=0x85;_tb0e=1;			//fPSC0=fSYS/4,�g��=8192*(1/fPSC0),�P��TB0���_
	_sadc0=0b00111000;							//ADEN=ADRFS=1, SAC[3:0]=1000(���AN8)
	_sadc1=0x07;								//SAINS[3:0]=0000(���ANn),SACKS[2:0]=7(fSYS/128)
	_sadc2=0b00000000;							//SAVR[1:0]=0000(���vREF=Intrrnal A/D Power)
	_pds0=0x03;									//�]�mPD0�\�ରAN8
	ptr=Buffer; ScanCode=0b00000001;		    //���Ъ�ȳ]�w
	for(i=0;i<4;i++) Buffer[i]=0;				//��ܪ�ȳ]�w
	_emi=1;										//�P��EMI
	_start=1; _start=0;
	while(1)
	{	_start=1; _start=0;						//�Ұ�A/D�ഫ
		while(_adbz);							//�����ഫ����
		adr=((u16)_sadoh<<8)|_sadol;			//���o12-bit���ഫ���G
		
		adr = ((u32)adr * 5000)/4096;
		
		
		
		
		
		Buffer[3]=adr/1000; adr%=1000;			//���o�d���
		Buffer[2]=adr/100; 	adr%=100;			//���o�ʦ��	
		Buffer[1]=adr/10;   adr%=10;			//���o�ɦ��
		Buffer[0]=adr;							//���o�Ӧ��
	}									
}
DEFINE_ISR(ISR_TB0,0x24)
{	SEGPort=0;									//�����C�q
	ScanPort=ScanCode;							//�e�X���y�X								
	SEGPort=SEG_TAB[*ptr++];					//�e�X�`�q�X
	GCC_RL(ScanCode);							//��s���y�X
	if(ScanCode==0b00010000)
		SEGPort^=(1<<7);
	if(ScanCode==0b00010000)					//�Y�w�����|���C�q
	{	ScanCode=0b00000001; ptr=Buffer;	    //���s��l���лP���y�X	
	}
}