// PROGRAM	: U3_2.c										2017.0427
// FUNCTION	: Dot Matrix LED with Source Current Control 	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	 DotPort	_pg									//Connect to ESK-200 PD
#define  DotPortC	_pgc
#define	 ScanPort	_pf									//Connect to ESK-200 PE
#define	 ScanPortC	_pfc
void Delayms(u16);
const u8 TabStop[8] ={0x18,0x18,0x3C,0x5A,0x5A,0x24,0x24,0x66};
const u8 TabWalk1[8]={0x3C,0x1C,0x08,0x0C,0x1A,0x28,0x14,0x14};
const u8 TabWalk2[8]={0x78,0x38,0x10,0x3E,0x4B,0xC8,0x16,0x63};
const u8 TabWalk3[8]={0x78,0x38,0x10,0x18,0x18,0x18,0x18,0x38};		  	 
const u8 TabWalk4[8]={0x78,0x38,0x10,0x18,0x2C,0x28,0x14,0x14};
const u8 TabWalk5[8]={0x3C,0x1C,0x08,0x3C,0x6A,0x4B,0x34,0x22};
volatile u8 ScanCode;
const u8 *ptr,*ptrbk;									//�����ܼƫŧi
void main()
{	u8 i,j,TabIndex;
	_wdtc=0b10101111;									//�����ݭ̪��p�ɾ�
	ScanPort=0; ScanPortC=0;							//�W��ScanPort����X�ݩʨòM��
	DotPort=0; DotPortC=0;								//�W��DotPort����X�ݩʨòM��
	_psc0r=0x01; _tb0c=0x04; _tb0e=1;					//fPSC0=fSYS/4,�g��=8192*(1/fPSC0),�P��TB0���_
	_emi=1;												//�P��EMI	
	ScanCode=0b00000001;								//ScanCode��ȳ]�w
	while(1)
	{	ptrbk=TabStop; ptr=TabStop;						//�����ܼƫ��VTabStop[]�_�l��}				
		_tb0on=1;										//�Ұ�TB0�p��
		for(i=0;i<30;i++)
		{	Delayms(300);								//����0.3 Sec
			_sledc2^=0xF0; _sledc3^=0x0F;				//PG, PF���y Level 0/3����
		}
		_tb0on=0; DotPort=0;							//�Ȱ�TB0�p��
		for(j=0;j<20;j++)
		{	TabIndex=0;									//TabIndex��ȳ]�w
			while(TabIndex++ < 6)						//�O�_TabIndex<6 ?
			{	switch(TabIndex)						//�ھ�TabIndex���e�Nptrbk���V�U�}�C�_�l��}
				{	case 1:	ptrbk=TabWalk1;				//ptrbk���VTabWalk1�}�C�_�l��}
							break;
					case 2:	ptrbk=TabWalk2;				//ptrbk���VTabWalk2�}�C�_�l��}
							break;
					case 3:	ptrbk=TabWalk3;				//ptrbk���VTabWalk3�}�C�_�l��}
							break;
					case 4:	ptrbk=TabWalk4;				//ptrbk���VTabWalk4�}�C�_�l��}
							break;
					case 5:	ptrbk=TabWalk5;				//ptrbk���VTabWalk5�}�C�_�l��}
							break;
				}		
				ptr=ptrbk; ScanCode=0b00000001;			//ptr���V�}�C�_�l��}�ó]�wScanCode���
				if(j<10) i=150; else i=60;
				_tb0on=1; Delayms(i);					//�Ұ�TB0�p�ƨé��� i ms
				_tb0on=0; DotPort=0;					//�Ȱ�TB0�p�ƨòM��DotPort
			}			
		}
	}
}
DEFINE_ISR(ISR_TB0,0x24)
{	DotPort=0;											//�M��DotPort
	ScanPort=ScanCode; DotPort=*ptr++;					//�������y�P��ơA�P�ɶi����л��W
	GCC_RL(ScanCode);									//��s���y�X
	if(ScanCode==0b00000001) ptr=ptrbk;					//�Y�w�����K�歫�s�]�w����	
}
void Delayms(u16 del)
{	u16 i;												//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}