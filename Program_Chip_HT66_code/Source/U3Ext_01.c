// PROGRAM	: U3Ext_01.c						2020.0325
// FUNCTION	: Multi 7 SEGMENT LED Control 	   	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	 SEGPort	_pg
#define  SEGPortC	_pgc
#define	 ScanPort	_pe
#define	 ScanPortC	_pec
const u8 SEG_TAB[] = {			   				//7-Segment Table
			0x3F,0x06,0x5B,0x4F,0x66,
			0x6D,0x7D,0x07,0x7F,0x67};
volatile _Bool FG_100ms,FG_GoStop;
volatile u8 *ptr,R100ms,ScanCode,Digit[4];
void main()
{	u8 i;
	_wdtc=0b10101111;							//關閉看們狗計時器
	SEGPort=0; SEGPortC=0; 						//Config Port as Output
	ScanPort&=0xF0; ScanPortC&=0xF0;
	_stm2c0=0;									//fINT=fSYS/4(0.5us)
	_stm2c1=0b11000001;							//Timer/Counter, TM2A Match Clear
	_stm2al=(u8)10000; _stm2ah=10000>>8;        //TM2A=10000 (10000*1us=5ms)
	_ifs0=0x00;									//INT0 --> PA1
	_papu1=1;									//Pull-Up
	_integ=0b00000010;							//INT0 Falling Edge
	_int0e=1;									//Enable INT0 Interrupt
	R100ms=20; FG_100ms=0;						//Initial Counter(20*5ms)=0.1 Sec
	ptr=Digit; ScanCode=0b10000000;		      	//Initial Pointer
	for(i=0;i<4;i++) Digit[i]=0;				//Initial Count
	_mf4e=1; _stm2ae=1;							//Enable STM2 Interrupt
	_emi=1; _st2on=1; FG_GoStop=0;				//Start STM2, Interrupt
	while(1)
	{	while(!FG_100ms);						//Wait for 0.1 Sec
		FG_100ms=0;
		if(++Digit[0]==10)						//更新0.1秒變數
		{	Digit[0]=0;
			if(++Digit[1]==10)					//更新秒(個位數)
			{	Digit[1]=0;
				if(++Digit[2]==6)				//更新秒(十位數)
				{	Digit[2]=0;
					if(++Digit[3]==10) Digit[3]=0;//更新分(個位數)
				}
			}
		}
	}	
}
DEFINE_ISR(ISR_ExtInt0,0x04)
{	_emi=1; _int0e=0;							//Enable Nest Interrupt
	FG_GoStop=!FG_GoStop;						//Update FG_GoStop
	GCC_DELAY(25000); GCC_DELAY(25000);			//25ms Delay
	_int0f=0;									//for Bouncing
	_int0e=1;
}
DEFINE_ISR(STM2,0x38)
{	SEGPort=0;									//Turn-off 7-Seg
	GCC_RL(ScanCode);							//Update Scan Code
	if(ScanCode==0b00010000)
	{	ScanCode=0b00000001; ptr=Digit;	      	//Restart ScanCode	
	}
	ScanPort=ScanCode;									
	if(ScanCode==0x02 || ScanCode==0x08) SEGPort=(SEG_TAB[*ptr++]|(1<<7));
	else SEGPort=SEG_TAB[*ptr++];
	if(FG_GoStop)
	{ 	if(--R100ms==0)
		{	FG_100ms=1;
			R100ms=20;
		}
	}
	_stm2af=0;			
}