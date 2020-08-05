/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern void led_main (void);
extern void LedChange(uint8_t mode);
extern volatile uint8_t melody_number;

//volatile uint32_t msTicks;         // Counter for millisecond Interval

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Key_1 1
#define Key_2 2
#define Key_3 3
#define Key_4 4
#define Key_default 10


volatile uint8_t key_number;
#define AllLed_on  1
#define AllLed_off 2
#define OddLed_on  3 
#define EvenLed_on 4
#define BitLed_on  5


//---------------------------------------------

#define soundStop 150
#define Song_off 0
#define Song_1   1
#define Song_2   2
#define Song_3   3
#define Song_4   4

//-------------------------
void Config_PA0PA1(void)                        
{
	RCC->AHBENR |= 0x1ul << 17;                 // Enable ... clock 
	GPIOA->MODER &= ~( 0x3ul | 0x3ul << 1*2);   // Set PA0、PA1 is input
	
	RCC->APB2ENR |= 0x1ul;
	SYSCFG ->EXTICR[0] &= ~( 0xful | 0xful <<1*4);
	
	EXTI->FTSR |= 0x1ul | 0x1ul << 1;          //Falling trigger selection register
	
	EXTI->IMR |= 0x1ul | 0x1ul << 1;           //Interrup mask register

	EXTI->PR |= 0x1ul | 0x1ul << 1;	          //pending register
	
	NVIC_SetPriority(EXTI0_1_IRQn, 3);        //IRQ5 優先度 3
	NVIC_EnableIRQ(EXTI0_1_IRQn);
	
}
//-----------------------------------------------
void EXTI0_1_IRQHandler (void)
{
	uint32_t prValue;
	
//	printf("IRQ 5 int.\n\r");
	
	prValue =EXTI->PR;
		
	if ((prValue & 0x1ul) == 1)
	{
		if ((GPIOA->IDR & 0x1ul) == 0)
		{
			key_number = Key_1;            //中斷只記錄，處理工作放在主程式
			printf("PA.0 int.\n\r");
			melody_number=Song_1;
		}
		EXTI->PR |= 0x1ul;                 //中斷一定要清除
	}
	
	if ( (prValue & (0x1ul << 1) ) != 0)
	{	
		if  ( (GPIOA->IDR & (0x1ul << 1) ) ==0)
		{
			key_number = Key_2;
			printf("PA.1 int. \n\r");
			melody_number=Song_2;
		}
		EXTI->PR |= 0x1ul <<1;
	}
//	EXTI->PR |= 0x1ul | 0x1ul << 1;
}

//------------------------------
void Config_PB3PB5(void)
{
	RCC->AHBENR |= 0x1ul << 18;                 // Enable GPIOB clock 
	GPIOB->MODER &= ~( 0x3ul << 3*2 | 0x3ul << 5*2 );   // Set PB3、PB5 is input
	
	RCC->APB2ENR |= 0x1ul;                      // Enable SYSCFG
		
	SYSCFG ->EXTICR[0] &= ~( 0xful << 3*4 );
	SYSCFG ->EXTICR[0] |= 0x1ul << 3*4;

	SYSCFG ->EXTICR[1] &= ~( 0xful << 1*4 );
	SYSCFG ->EXTICR[1] |= 0x1ul << 1*4;	
	
	EXTI->FTSR |= 0x1ul << 3 | 0x1ul << 5;          //Falling trigger selection register
	EXTI->IMR |= 0x1ul << 3 | 0x1ul << 5;           //Interrup mask register
	EXTI->PR |= 0x1ul << 3 | 0x1ul << 5;	          //pending register
	
	NVIC_SetPriority(EXTI2_3_IRQn, 3);        //IRQ5 優先度 3
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	
	NVIC_SetPriority(EXTI4_15_IRQn, 3);        //IRQ5 優先度 3
	NVIC_EnableIRQ(EXTI4_15_IRQn);
}
	
//-------------------------------------------
void EXTI2_3_IRQHandler(void)
{
	uint32_t prValue;
//	printf("IRQ 6 int.\n\r");
//	EXTI->PR |= 0x1ul << 3;
	
	prValue =EXTI->PR;
		
	if ( (prValue & (0x1ul << 3)) == (0x1ul << 3) )
	{
		if ((GPIOB->IDR & (0x1ul << 3) ) == 0)
		{
			key_number = Key_3;            //中斷只記錄，處理工作放在主程式
			printf("PB.3 int.\n\r");
			melody_number=Song_3;
		}
	}
	EXTI->PR |= 0x1ul << 3;                 //中斷一定要清除
}

//-----------------------------------------
void EXTI4_15_IRQHandler(void)
{	
	uint32_t prValue;
//	printf("IRQ 7 int.\n\r");
//	EXTI->PR |= 0x1ul << 5;
	
	prValue =EXTI->PR;
	if ((prValue & (0x1ul << 5)) == (0x1ul <<5 ) )
	{
		if ((GPIOB->IDR & (0x1ul << 5) ) == 0)
		{
			key_number = Key_4;            //中斷只記錄，處理工作放在主程式
			printf("PB.5 int.\n\r");
			melody_number=Song_4;
		}
	}	
	EXTI->PR |= 0x1ul << 5;                 //中斷一定要清除
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void key_main (void) {        // User application starts here
	
	
	Config_PA0PA1();
	Config_PB3PB5();
	
	led_main();
	
	key_number=Key_default;
		
	
//	for (;;){    }       //CPU idle	
}