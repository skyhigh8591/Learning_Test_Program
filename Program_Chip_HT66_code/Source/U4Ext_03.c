// PROGRAM	: U4Ext_03.c									2020.0320
// FUNCTION	: PTM2 PWM Output Mode Speaker Volume Control  	By Steven
// NOTE		: PD2->to Buzzer or Speaker(Recommend)
//			: Buzzer礙於ESK310硬體設計限制,僅能以Active-Hi驅動
//			: Speaker為外接型式,改以Active-Lo驅動(一端接VCC),更凸顯音量差異
#define Speaker												//Mark if Using Buzzer
#include <HT66F2390.h>
#include "MyType.H"
#define fSYS   8000000										//8MHz System Frequency
const u16 Pitch_TAB[] = {			      					//Pitch Control Table
			fSYS/523,fSYS/587,fSYS/659,
			fSYS/698,fSYS/785,fSYS/880,
			fSYS/998,fSYS/(523*2),fSYS/(587*2),
			fSYS/(659*2),fSYS/(698*2),fSYS/(785*2),
			fSYS/(880*2),fSYS/(998*2),fSYS/(523*4),
			fSYS/(587*4)};
void Delayms(u16);
u8 ScanKey(void);
void main()
{	u8 Pitch,i; u16 duty;							
	_wdtc=0b10101111;										//關閉看們狗計時器
	_pds0=0x10;												//Enable PD2 as PTP2 Function
	_sledc1|=(3<<3);										//for Buzzer Active Hi
#ifdef	Speaker												//注意：Buzzer Active Hi, Speaker Active Low(V+ to VCC)
	_ptm2c0=0x10; _ptm2c1=0b10100000;						//PTM2: fINT=fSYS, PWM OP, PTM2RP for Period, Active-Lo
#else
	_ptm2c0=0x10; _ptm2c1=0b10101000;						//PTM2: fINT=fSYS, PWM OP, PTM2RP for Period, Active-Hi
#endif	
	while(1)				
	{	for(i=10;i!=0;i--)
		{	for(Pitch=0;Pitch<8;Pitch++)
			{ 	duty=Pitch_TAB[Pitch]>>i;
				_ptm2rpl=(u8)Pitch_TAB[Pitch];				//TM2AL Shold be Loaded First !!
				_ptm2rph=Pitch_TAB[Pitch]>>8;
				_ptm2al=(u8)duty; _ptm2ah=duty>>8;			//Set Duty 
				_pt2on=1;									//Start STM0
				Delayms(200); _pt2on=0; 					//Delay 250mS, Stop STM0
			}
		}
	}
}
void Delayms(u16 i)
{	u16 j;
	for(j=0;j<i;j++) GCC_DELAY(2000);						//Delay i*1ms
}	