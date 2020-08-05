// PROGRAM	: HUExt_01.c							2020.0325
// FUNCTION	: Multi 7 SEGMENT LED Control 	      	By Steven
#include <HT66F2390.h>
#include "MyType.H"
#define	 SEGPort	_pg
#define  SEGPortC	_pgc
#define	 ScanPort	_pe
#define	 ScanPortC	_pec
const u8 SEG_TAB[] =	{			   				//7-Segment Table
			         0x3F,0x06,0x5B,0x4F,0x66,
			         0x6D,0x7D,0x07,0x7F,0x67};
volatile _Bool FG_100ms,FG_GoStop;
volatile u8 *ptr,R100ms,ScanCode,Digit[4];
void main()
{	u8 i;
	u8 min=59,hour=23;								//設定初始時間
	_wdtc=0b10101111;								//關閉WDT
	SEGPort=0; SEGPortC=0; 							//Config Port as Output
	ScanPort&=0xF0; ScanPortC&=0xF0;
	_stm2c0=0;										//fINT=fSYS/4(0.5us)
	_stm2c1=0b11000001;								//Timer/Counter, STM2A Match Clear
	_stm2al=(u8)10000; _stm2ah=10000>>8;        	//STM2A=10000 (10000*0.5us=5ms)
	_ifs2=0x00;										//INT0 --> PA1
	_papu1=1;										//Pull-Up
	_integ=0b00000010;								//INT0 Falling Edge
	_int0e=1;										//Enable INT0 Interrupt
	R100ms=200; FG_100ms=0;							//Initial Counter(200*5ms)=1 Sec
	ptr=Digit; ScanCode=0b10000000;		   			//Initial Pointer
	for(i=0;i<4;i++) Digit[i]=0;					//Initial Count
	
	Digit[1]=min/10;  Digit[0]=min%10; 				//分別取得分鐘十/個位數
	Digit[3]=hour/10; Digit[2]=hour%10; 			//分別取得小時十/個位數

//	Digit[1]=5; Digit[0]=9;							//設定初始時間
//	Digit[3]=2; Digit[2]=3;							//

	_mf4e=1; _stm2ae=1;								//Enable TM2 Interrupt
	_emi=1; _st2on=1; FG_GoStop=0;					//Start TM2, Interrupt
	while(1)
	{	while(!FG_100ms);							//Wait for 1 Sec
		FG_100ms=0;										
/*		if(++Digit[0]==10)							//更新分(個位數)
		{	Digit[0]=0;
			if(++Digit[1]==6)						//更新分(十位數)
			{	Digit[1]=0; 
				if(++Digit[2]==4 && Digit[3]==2)	//更新時(個位數),並Check 24:00 
				{	Digit[2]=0; Digit[3]=0;
				}
				else if(Digit[2]==10) 				
				{	Digit[2]=0;						//更新時(十位數)
					Digit[3]++;
				}
			}
		}
*/
		if(++min==60)
		{	min=0;
			if(++hour==24) hour=0;
		}
		Digit[1]=min/10;  Digit[0]=min%10; 			//分別取得分鐘十/個位數
		Digit[3]=hour/10; Digit[2]=hour%10; 		//分別取得小時十/個位數
	}	
}
DEFINE_ISR(ISR_ExtInt0,0x04)
{	_emi=1; _int0e=0;								//Enable Nest Interrupt
	FG_GoStop=!FG_GoStop;							//Update FG_GoStop
	GCC_DELAY(20000);								//10ms Delay
	_int0f=0;										//for Bouncing
	_int0e=1;
}
DEFINE_ISR(ISR_STM,0x38)
{	static u8 sec=0;
	SEGPort=0;										//Turn-off 7-Seg
	GCC_RL(ScanCode);								//Update Scan Code
	if(ScanCode==0b00010000)
	{	ScanCode=0b00000001; ptr=Digit;	      		//Restart ScanCode	
	}
	ScanPort=ScanCode;									
/*=============== Connect PG7 to dp or dps=====================*/
	//4 DPs Flash with rate=0.5 sec	
//	if(R100ms<100 ) SEGPort=SEG_TAB[*ptr++];	
//	else SEGPort=(SEG_TAB[*ptr++]|0b10000000);
/*================ Connect PG7 to dp =========================*/
	//Each DP Turn-On 1 sec then Change to Next one 
	if(1<<(sec%4)==ScanCode ) SEGPort=(SEG_TAB[*ptr++]|(1<<7));
	else SEGPort=SEG_TAB[*ptr++];
/*===================================================*/
//	if(FG_GoStop)
	{ if(--R100ms==0)
		{	//FG_100ms=1;
			R100ms=200;
			if(++sec==60)
			{	sec=0;	
				FG_100ms=1;
			}
		}
	}
	_stm2af=0;			
}