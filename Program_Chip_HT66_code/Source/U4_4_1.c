// PROGRAM	: U4_4_1.c							2017.0505
// FUNCTION	: LCM(1602A) COntrol Demo Program	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	 pLCMEN		_pe2	
#define  pLCMRW		_pe1	
#define  pLCMRS		_pe0	
#define  pLCMENC	_pec2	
#define  pLCMRWC	_pec1	
#define  pLCMRSC	_pec0	
#define  LCMData	_pg
#define  LCMDataC	_pgc	   
void LCMInit(void);
u8 LCMWrite(_Bool, u8);
void Delayms(u16);								//�禡�쫬�ŧi		 
void main()
{	volatile u8 i;
	_wdtc=0b10101111;							//�����ݭ̪��p�ɾ�
	LCMInit();				       				//LCM��l�]�w
	while(1)
	{	LCMWrite(0,0x01);						//�M��LCM��ܡB����k��						
		for(i=0;i<16;i++)
		{	LCMWrite(1,'1'); Delayms(200);		//���"1"�é���0.2��
		}
		LCMWrite(0,0x04);						//�i�J�Ҧ�:Decrease, Not Shift
		LCMWrite(0,0xCF);						//Set Line 2, Position 0
		do
		{	Delayms(100);						//����0.1��
		} while(LCMWrite(1,'2')>(0x40)); 		//���"2"�çP�_�O�_��F�C2��0
		Delayms(1000);							//����1��
	}
}
void LCMInit(void)
{	pLCMEN=0; pLCMRW=0; pLCMRS=0;	        	//�]�wEN/RW/RS�}�쬰�C�q��
	pLCMENC=0; pLCMRWC=0; pLCMRSC=0;	  		//�]�wEN/RW/RS�}�쬰��X�Ҧ�
	Delayms(40);								//LCM Power-On Time
	LCMWrite(0,0x38);							//�\��]�w:8-Bit, 2-Line, 5*7
	LCMWrite(0,0x0F);							//��ܱ���:Display/Cursor Blinking On
	LCMWrite(0,0x06);							//�i�J�Ҧ�:Increse, Not Shift
	LCMWrite(0,0x01);							//�M��LCMy
}
u8 LCMWrite(_Bool fgCD,u8 CD)
{	u8 BusyAC;
	LCMDataC=0b11111111;						//�W��Port����J�Ҧ�
	pLCMRS=0; pLCMRW=1;							//RS=0,RW=1 (Read IR)
	GCC_NOP(); 									//tAS
	do
	{	pLCMEN=1; GCC_NOP();					//EN=1,tDDR
		BusyAC=LCMData;							//Ū��LCM IR
		pLCMEN=0;								//EN=0	
	} while (BusyAC & 1<<7);					//�YLCM���L,�A��Ū��
	LCMDataC=0;									//�W��Port����X�Ҧ�
	pLCMRW=0;									//RW=0 (Write)
	pLCMRS=fgCD;								//��fgCD�ȳ]�m RS�}�쪬�A
	LCMData=CD;									//�e�X��ƩΩR�O
	pLCMEN=1; GCC_NOP(); pLCMEN=0; 				//EN=1,tPW,EN=0
	return BusyAC;								//�^��Address Counter
}
void Delayms(u16 del)
{	u16 i;										//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}