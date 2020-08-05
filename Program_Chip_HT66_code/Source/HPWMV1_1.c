// PROGRAM	: H4-13-1.c								2019.0514
// FUNCTION	: Software PWM Implection for LEDs     	By Steven
//            With AD0 to Control Speed
#include <HT66F2390.h>
#include "MyType.H"
#define LEDPort		_pc
#define LEDPortC	_pcc
const u8 Tab[]={5,15,30,40,50,60,70,80};
u8 DEL;
void main()
{	u8 i,j,LED,LED1,LED2;
   	_wdtc=0b10101111;								//關閉看們狗計時器
	LEDPort=(u8)~0; LEDPortC=0;						//Config Port as O/P Mode
	_sadc0=0b00101000;								//ADEN=1,ADRFS=0, SAC[3:0]=1000(選擇AN8)
	_sadc1=0x07;									//SAINS[3:0]=0000(選擇ANn),SACKS[2:0]=7(fSYS/128)
	_sadc2=0b00000000;								//SAVR[1:0]=0000(選擇vREF=Intrrnal A/D Power)
	_pds0=0x03;										//設置PD0功能為AN8
	_ade=1; _emi=1;									//Enable ADC Interrupt 	
	_start=1; _start=0;	
	while(1)
	{	LED=(u8)~0x01; LED2=(u8)~0b11011111;     	//Set Initial State
		for(i=0;i<12;i++)                  			//Counting Loop               
		{	for(j=0;j<DEL;j++)                   	//Speed Contol Loop
				{	LED1=LED2;
					LEDPort=LED; GCC_DELAY(50); 	//Duty=25/4000
					LEDPort|=LED1; GCC_DELAY(450);	//Duty=250/4000
					GCC_RL(LED1);
					LEDPort|=LED1; GCC_DELAY(1500);	//Duty=1000/4000     
					GCC_RL(LED1);
					LEDPort|=LED1; GCC_DELAY(6000);	//Always on
				}	
			if (i<=2) LED<<=1; 
			else LED=(LED<<1)|0x01;
			GCC_RL(LED2);
		}
		LED=(u8)~0x80; LED2=(u8)~0b11111011;   		//Set Initial State
		for(i=0;i<12;i++)                         	//Counting Loop  
		{	for(j=0;j<DEL;j++)                      //Speed Contol Loop
				{	LED1=LED2;
					LEDPort=LED; GCC_DELAY(50);  	//Duty=25/4000
					LEDPort|=LED1; GCC_DELAY(450);	//Duty=250/4000
					GCC_RR(LED1);
					LEDPort|=LED1; GCC_DELAY(1500);	//Duty=1000/4000
					GCC_RR(LED1);
					LEDPort|=LED1; GCC_DELAY(6000);	//Always on
				}
			if (i<=2) LED>>=1; 
			else LED=(LED>>1)|0x80;
			GCC_RR(LED2);
		}
	}
}
DEFINE_ISR(ISR_ADC,0x1C)
{	DEL=Tab[_sadoh>>5];
	_start=1; _start=0;
}