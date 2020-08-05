// PROGRAM	: PWM.c											2019.0701
// FUNCTION	: PTM0 Timer Mode for PWMs Generation(Static)	By Steven
// Note		: Change to ESK300 Low Active LEDs(PC->LEDs)
#include <HT66F2390.h>
#include "MyType.H"
const u8 PWM_TAB[] = {1,15,50,240,0,0,0,0};				//Duration Control
volatile u8 PWM[8],PWMBuf[8];
volatile u8 Period;
void Delayms(u16);
void main()
{	u8 i;
	_wdtc=0xAF;											//Disable WDT			            	
	_pcc=0; _pc=0xFF;
	_mf0e=1; _ptm0ae=1; 								//Enable MF0 and PTM0A Interrupt
	_ptm0c0=0; _ptm0c1=0b11000001;                 		//fINT=fSYS/4,Timer/Counter, PTM0A Match Clear
	_ptm0af=0; _mf0f=0; _emi=1;                    		// Enable Interrupt
	_ptm0al=(u8)199; _ptm0ah=199>>8;		         	//100us 
	Period=250;											//PWM Period Control		
	for(i=0;i<8;i++) PWM[i]=PWM_TAB[i];					//Load Duty Constant
	_pt0on=1;
	while(1);											//Looping
}
DEFINE_ISR(ISR_STM,0x14)
{	u8 i;
	if(Period++>=249)									//Period Checking
	{	Period=0;										//New Period
		for(i=0;i<8;i++) PWMBuf[i]=PWM[i];				//Re-load Duty Constant	
		if(PWMBuf[0]!=0) _pc0=0;						//PWM Output Low(Active Low) if Duty not Zero
		if(PWMBuf[1]!=0) _pc1=0;
		if(PWMBuf[2]!=0) _pc2=0;
		if(PWMBuf[3]!=0) _pc3=0;
		if(PWMBuf[4]!=0) _pc4=0;
		if(PWMBuf[5]!=0) _pc5=0;
		if(PWMBuf[6]!=0) _pc6=0;
		if(PWMBuf[7]!=0) _pc7=0;		
	}
	else
	{	if(PWMBuf[0]==0) _pc0=1; else PWMBuf[0]--;		//Switch to Inactive Level
		if(PWMBuf[1]==0) _pc1=1; else PWMBuf[1]--;
		if(PWMBuf[2]==0) _pc2=1; else PWMBuf[2]--;
		if(PWMBuf[3]==0) _pc3=1; else PWMBuf[3]--;
		if(PWMBuf[4]==0) _pc4=1; else PWMBuf[4]--;
		if(PWMBuf[5]==0) _pc5=1; else PWMBuf[5]--;
		if(PWMBuf[6]==0) _pc6=1; else PWMBuf[6]--;
		if(PWMBuf[7]==0) _pc7=1; else PWMBuf[7]--;
	}
	_ptm0af=0;											//Clear PTM0AF
}
void Delayms(u16 del)
{	u16 i;
	for(i=0;i<del;i++) GCC_DELAY(2000);					//Delay i*1ms
}
