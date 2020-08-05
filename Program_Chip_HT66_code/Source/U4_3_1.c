// PROGRAM	: U4_3_1.c								2017.0501
// FUNCTION	: PTM PWM Motro Control with H-Bridge 	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	SEGPort			_pg
#define	SEGPortC		_pgc
#define	SW_SpeedUpPU	_pcpu0	
#define	SW_SpeedUp		_pc0	
#define	SW_SpeedUpC		_pcc0	
#define	SW_SpeedDownPU	_pcpu1		
#define	SW_SpeedDown	_pc1	
#define	SW_SpeedDownC	_pcc1	
#define	SW_DirectionPU	_pcpu2	
#define	SW_Direction	_pc2	
#define	SW_DirectionC	_pcc2	
const u8 SEG_TAB[] = {0x3F,0x06,0x5B,0x4F,0x66,		//�C�q��ܽX�ت��(�@��)
			 		  0x6D,0x7D,0x07,0x7F,0x67};
const u16 PWM_TAB[] = {0,512,1024,1536,2048,		//PWM�`�ƫت��
			 		   2560,3072,3584,4096,4608};
void Delayms(u16);									//�禡�쫬�ŧi		 
void main()
{	s8 Index=0;								
	_wdtc=0b10101111;								//�����ݭ̪��p�ɾ�
	SEGPort=0; SEGPortC=0; 							//�W��SEGPort����X�ݩ�,�ÿ�X0
	SW_SpeedUpC=1; SW_SpeedUpPU=1;			   		//�W������}�쬰��J�ݩʨñҥδ��ɹq��
	SW_SpeedDownC=1; SW_SpeedDownPU=1;		   	
	SW_DirectionC=1; SW_DirectionPU=1;		   	
	_pb2=0; _pbc2=0; _pd4=0; _pdc4=0;				//�W��PB2/PD4����X�ݩʨÿ�X0
	_pbs0=0x30; _pds1=0x00;							//PB2��PTP3�\��BPD4��I/O�\��
	_ptm3rpl=(u8)4608; _ptm3rph=4608>>8;			//PWM �g��=4608/fINT
	_ptm3c0=0b00111000;								//fINT=fSYS(8MHz)/64(8us),�_�lPTM3�p��
	_ptm3c1=0b10101000;								//PWM Mode, Active High
	while(1)
	{	SEGPort=SEG_TAB[Index];
		if(_pds1==0x02) SEGPort|=1<<7;				//��������dp�`�q
		_ptm3al=(u8)PWM_TAB[Index]; 				//���o���Ť�Ѽ�
		_ptm3ah=PWM_TAB[Index]>>8;
		Delayms(250);								//����250ms
		while(1)
		{	if(!SW_SpeedUp)
			{	if(++Index>9) Index=9;				//�Y���U�[�t��,���л��W(�W��9) 
				break;   	
			}
			else if(!SW_SpeedDown) 					//�Y���U��t��,���л���(�U��0) 
			{	if(--Index<0) Index=0;
				break;   	
			}
			else if(!SW_Direction)
			{	if(_pds1==0)						//�O�_������?
				{	_pbs0=0x00; _pds1=0x02;			//�O,PB2��I/O�\��BPD4��PTP3�\��
				}
				else								//�_
				{	_pbs0=0x30; _pds1=0x00;			//PB2��PTP3�\��BPD4��I/O�\��
				}
				break;
			}
		}
	}
}
void Delayms(u16 del)
{	u16 i;											//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}