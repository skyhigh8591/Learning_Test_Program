// PROGRAM 	:U2_3_1.c							2017.0424
// FUNCTION : SLEEP Mode with WDT Demo Program	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	SEGPort		_pg							//DEFINE 7-SEG PORT
#define	SEGPortC	_pgc						//DEFINE 7-SEG PORT CONTROL REG.
#define SW0  		_pa1
#define SW0C  		_pac1
#define SW0PU  		_papu1
#define SW0WU  		_pawu1
#define SW1PU  		_papu7
const u8 SEG_TAB[] = {			   				//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
void WDT_WakeUp(void);
void Delayms(u16);
void main()
 {	static u8 Index; 							//Index������Static���A,�_�h��ȷ|�M����0
	u8 SleepCount;
	_wdtc=0b01010110;							//�P��ݭ̪��p�ɾ�,Time-out=2^17/fS
	SEGPort=0; SEGPortC=0;						//�W��SEGPort����X�ݩʨÿ�X0
	SW0C=1; SW0PU=1; SW0WU=1;		   			//�P��G��J�ݩ�/���ɹq��/����\��
	SW1PU=1; _int1ps=1;							//�P�ണ�ɹq���A���wINT1�\���PA7�}���{
	_integ=0b00001000;							//���INT1���t�tĲ�o
	_fhiden=0; _fsiden=0;						//HALT���O�����A������/�C�W�_���q��
	Delayms(300); _rstc=0xAA;					//�P��RES�}�쭫�m�\��
	if(_pdf) 									//If PDF=1 ?
	{	if(_to) WDT_WakeUp();					//Yes. If WDT Overflow, call WDT_WakeUp()
		GCC_CLRWDT();							//Clear PDF
	} 
	else										//Power-on Reset
	{	Index=0;
	}
	while(1)
	{	SEGPort=SEG_TAB[Index];					//���INDEX�� 
		Delayms(200); 							//���� 0.2 Sec
		SleepCount=50;
		do
		{	Delayms(100); 						//���� 0.1 Sec
			GCC_CLRWDT();
			if(--SleepCount==0)					//0.1 Sec*50=5 Sec 
			{	SEGPort=0;						//�����C�q��ܾ�
				_int1f=0;						//�M��INT1�X��
				_emi=1; _int1e=1;				//�P��G���_�`�}��/INT1���_
				_halt();						//�i�JSLEEP Mode
				_emi=0; _int1e=0;				//�T��G���_�`�}��/INT1���_	
				break;							//����do...while�j��
			}
		} while(SW0);							//SW0�����A����do...while�j��
		if(++Index==10) Index=0; 				//�YIndex>10�h�k�s
		GCC_CLRWDT();
	}
}
void WDT_WakeUp(void)
{	u8 i;
	for(i=0;i<10;i++)							//�O,�{�{a��g�`�q
	{	SEGPort^=0xFF;
		Delayms(100);							//����0.1S
	}
}	
DEFINE_ISR(ISR_Int1,0x08)						//INT1 Interrupt Vector
{	u8 i;
	SEGPort=1<<7;								//�I�Gh�`�q
	do
	{	GCC_RL(SEGPort);	 					//���ۡA�I�G�U�@�`�q
		for(i=0;i<50;i++) GCC_DELAY(20000);  	//���� 0.5S
	} while(SEGPort!=(1<<6));
	_int1f=0;									//�קK�u���y���~�ʧ@
}
void Delayms(u16 del)
{	u16 i;										//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}