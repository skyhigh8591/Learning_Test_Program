// PROGRAM	: U4_2.c								2017.0428
// FUNCTION	: STM Compare Match O/P Mode Control   	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	SEGPort		_pg
#define	SEGPortC	_pgc
#define KeyPort		_pc
#define KeyPortC	_pcc
#define KeyPortPU	_pcpu
#define fSYS   8000000								//fSYS=8MHz
const u8 SEG_TAB[] = { 0x3F,0x06,					//7-Segment Table(0~F)
		0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,
		0x67,0x77,0x7C,0x58,0x5E,0x79,0x71};
const u16 Pitch_TAB[] = {			      			//���ձ`�ƫت��
		   fSYS/(523*2*4),fSYS/(587*2*4),fSYS/(659*2*4),
		   fSYS/(698*2*4),fSYS/(785*2*4),fSYS/(880*2*4),
		   fSYS/(998*2*4),fSYS/(523*4*4),fSYS/(587*4*4),
		   fSYS/(659*4*4),fSYS/(698*4*4),fSYS/(785*4*4),
		   fSYS/(880*4*4),fSYS/(998*4*4),fSYS/(523*8*4),
		   fSYS/(587*8*4)};
void Delayms(u16);		
u8 ScanKey(void);
void main()
{	u8 Key;
	_wdtc=0b10101111;								//�����ݭ̪��p�ɾ�
	SEGPort=0; SEGPortC=0;							//�M��SEGPort�óW������X�ݩ�
	_stm2c0=0; _stm2c1=0b00110001;					//STM2:���k�X��X�Ҧ�,CCRA�k�X�M��
	_pds1=0x20;										//�]�wPD6��STP2�\��	
	_sledc1=0xC0;									//�]�mPD[6:4]���y��Level 3	
	while(1)
	{	SEGPort=1<<7;								//�I�G�C�q��ܾ�h�`�q�A��l�`�q����
		do
		{ 	Key=ScanKey();
			GCC_DELAY(200000);  					//���� 100ms
			SEGPort^=(1<<7);						//�C�q��ܾ�h�`�q�G������
		} while(Key==16);	   						//���ݫ�������
		SEGPort=SEG_TAB[Key];				      	//�d�����ܫ����
		_stm2al=Pitch_TAB[Key];		         		//���o�p�Ʈɶ��`��
		_stm2ah=Pitch_TAB[Key]>>8;          
		_st2on=1;									//�Ұ�STM2�p��
		while (ScanKey()!=16);	                  	//���ݫ�������
		Delayms(300); _st2on=0; 					//����300mS,����p��
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
void Delayms(u16 del)
{	u16 i;											//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}	