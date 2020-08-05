// PROGRAM	: PWMV0.c							   2020.0323
// FUNCTION	: Software PWM Implection for LEDs     By Steven
// Has been Changed for ESK-300 Board
#include <HT66F2390.h>
#include "MyType.H"
#define LEDPort		_pc
#define LEDPortC	_pcc
void main()
{	u8 i,j,LED,LED1,LED2;
	_wdtc=0b10101111;								//關閉看們狗計時器
	LEDPort=~0; LEDPortC=0;							//Config Port as O/P Mode
	while(1)
	{	LED=(u8)~0x01; LED2=(u8)~0b11011111;         //Set Initial State
		for(i=0;i<12;i++)                  			//Counting Loop               
		{	for(j=0;j<40;j++)                   	//Speed Contol Loop
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
		LED=(u8)~0x80; LED2=(u8)~0b11111011;           		//Set Initial State
		for(i=0;i<12;i++)                         	//Counting Loop  
		{	for(j=0;j<20;j++)                      	//Speed Contol Loop
				{	LED1=LED2;
					LEDPort=LED; GCC_DELAY(50);  	//Duty=25/4000
					LEDPort |= LED1; GCC_DELAY(450);//Duty=250/4000
					GCC_RR(LED1);
					LEDPort |= LED1; GCC_DELAY(1500);//Duty=1000/4000
					GCC_RR(LED1);
					LEDPort |= LED1; GCC_DELAY(6000);//Always on
				}
			if (i<=2) LED>>=1; 
			else LED=(LED>>1)|0x80;
			GCC_RR(LED2);
		}
	}
}