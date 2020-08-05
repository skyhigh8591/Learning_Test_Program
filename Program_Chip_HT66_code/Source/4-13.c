// PROGRAM	: 4-13.c							2018.0910
// FUNCTION	: STM PWM O/P Mode Control   		By Steven
// NOTE:  	No ETM Change to Single PTM0
// ESK300,  Active High for	RGB LED(PC2), low for General LEDs
#include <HT66F2390.h>
#include "MyType.H"
#define	SW_BRIGHT	_pc0		
#define	SW_BRIGHTC	_pcc0		
#define	SW_BRIGHTPU	_pcpu0		
#define	SW_DARK		_pc1		
#define	SW_DARKC	_pcc1		
#define	SW_DARKPU 	_pcpu1		

const u16 TAB_PWM[] = {  						//Table (Duty Control)	
		10,50,100,200,300,400,500,600,800,1023};
void Delayms(u16 i);
void main()
{	u8 Index;
	_wdtc=0b10101111;							//關閉看們狗計時器
	SW_BRIGHTC=1 ; SW_DARKC=1;					//Set Port Bit as I/P Mode
	SW_BRIGHTPU=1; SW_DARKPU=1;				 	//Enable Port Bit Pull-up
	_pcs0=0x20;									//PC2 as PTP0
	_ptm0c0=0; 								 	//fINT=fSYS/4
	_ptm0c1=0b10101000;						  	//Active Low,Non-Inv.,P-match Clear
	_ptm0rpl=(u8)(1024-1); _ptm0rph=(1024-1)>>8;//Set PWM Period
	Index=5; _pt0on=1;							//Initial Index and Start ETM
	while(1)
	{	_ptm0al=(u8)TAB_PWM[Index];				//TM1BL Should be Loaded First !!
		_ptm0ah=TAB_PWM[Index]>>8;
		Delayms(500);							//Delay 0.5 Sec
		if(!SW_BRIGHT)
		{	if(Index<9) Index++;
		}
		else if (!SW_DARK)
		{	if(Index>0) Index--;
		}
	}
}
void Delayms(u16 i)
{	u16 j;
	for(j=0;j<i;j++)  GCC_DELAY(2000); 			//Delay 1ms*i
}