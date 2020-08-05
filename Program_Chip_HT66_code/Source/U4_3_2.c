// PROGRAM	: U4_3_2.c								2017.0501
// FUNCTION	: STM PWM DAC Demo Program 				By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	SEGPort			_pg
#define	SEGPortC		_pgc
#define	SW_FreqUpPU		_pcpu0	
#define	SW_FreqUp		_pc0	
#define	SW_FreqUpC		_pcc0	
#define	SW_FreqDownPU	_pcpu1		
#define	SW_FreqDown		_pc1	
#define	SW_FreqDownC	_pcc1	
#define	SW_WavePU		_pcpu2	
#define	SW_Wave			_pc2	
#define	SW_WaveC		_pcc2	
const u8 Sin_TAB[] = {								//SIN PWM�`�ƫت��
		128,203,250,250,203,128, 53,  6,  6, 53};
const u8 Tri_TAB[] = {								//Triangle PWM�`�ƫت��
		  0, 50,100,150,200,250,200,150,100, 50};
const u8* ptr=Sin_TAB;	  
bit fgWave=1;  
void Delayms(u16);									//�禡�쫬�ŧi
void main()
{	u16 sample=512;								
	_wdtc=0b10101111;								//�����ݭ̪��p�ɾ�
	SW_FreqUpC=1; SW_FreqUpPU=1;			   		//�W������}�쬰��J�ݩʨñҥδ��ɹq��
	SW_FreqDownC=1; SW_FreqDownPU=1;		   	
	SW_WaveC=1; SW_WavePU=1;		   	
	_pes0=0x08;										//PE1��STP0�\��
	_stm0rp=1; 										//PWM �g��=256/fIN
	_stm0c0=0b00011000;								//fINT=fSYS(8MHz),�_�lSTM0�p��
	_stm0c1=0b10101000;								//PWM, Active High,STM0RP����g��
	_stm2al=sample; _stm2ah=sample>>8; 				//�]�w���˶g���Ѽ�
	_stm2c0=0x18; _stm2c1=0b11000001;               //fINT=fSYS,�p��/�p�ƼҦ��AA�k�X�M��
	_stm2ae=1; _mf4e=1; _emi=1;						//�P��T2A���_,EMI�`�}��
	while(1)
	{	Delayms(200);								//����200ms
		while(1)
		{	if(!SW_FreqUp)							//���W��O�_���U?
			{	sample-=32;							//�O�A���ˮɶ��Ѽƭ��C
				if(sample<128) sample=128;			//�U���Ȱ���
				_stm2al=sample; _stm2ah=sample>>8; 	//�]�w���ˮɶ��Ѽ�			
				break;   	
			}
			else if(!SW_FreqDown) 					//���W��O�_���U?
			{	sample+=32;							//�O�A���ˮɶ��ѼƼW�[
				if(sample>2048) sample=2048;		//�W���Ȱ���
				_stm2al=sample; _stm2ah=sample>>8;  //�]�w���ˮɶ��Ѽ�				
				break;   	
			}
			else if(!SW_Wave) 						//�i������O�_���U?
			{	fgWave=!fgWave;						//�O�A�X�ФϺA
				break;
			}
		}
	}
}
DEFINE_ISR(ISR_STM2,0x38)
{	static u8 index=0;
	_stm0al=*ptr++; _stm0ah=0;						//���oDuty�Ѽ�
	if(++index>=10)									//���d���˴�
	{ 	index=0;									//�Y�W�L�d��h�^����
		ptr=(fgWave)? Sin_TAB : Tri_TAB;			//���o�ت��ư_�l��}
	}
	_stm2af=0;										//�M��STM2AF
}
void Delayms(u16 del)
{	u16 i;											//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}