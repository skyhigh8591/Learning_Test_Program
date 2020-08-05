/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern void Delay(uint32_t dlyTicks);
//extern volatile uint8_t key_number;

//volatile uint32_t msTicks;         // Counter for millisecond Interval

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Key_5 5
#define Key_6 6
#define Key_7 7
#define Key_8 8

#define white  0
#define red    6
#define blue   3 
#define green  5

//----------------------------------------------------------------------------
void GPIOA6_8_init(void)
{
	RCC->AHBENR |=0x1ul <<17;     //週邊 clock enable
	
	GPIOA->MODER &= ~((0x3ul<<6*2) | (0x3ul<<7*2) |(0x3ul<<8*2));   //output
	GPIOA->MODER |= (0x1ul<<6*2) | 0x1ul<<7*2 | 0x1ul<<8*2; 
	
	GPIOA->OSPEEDR &= ~((0x3ul<<6*2) | (0x3ul<<7*2) |(0x3ul<<8*2));  //設速度
	GPIOA->OSPEEDR |= 0x1ul<<6*2 | 0x1ul<<7*2 | 0x1ul<<8*2; 
}

//-----------------------------------------
void select_colorLED(uint8_t color)
{
	GPIOA->ODR &= ~(0x7ul << 6);
	GPIOA->ODR |=color<<6;
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void color_led_main (void) {        // User application starts here
	
//	uint32_t value;
//	
//		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
//    SetSysClock();
//	
//	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
//		                                            
//	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	
//	Button_Init();                     //使用前需初始化
	
	GPIOA6_8_init();
	GPIOA->ODR &= ~(0x7ul<<6);
	
//	for (int i=0;i<8;i++)
//	{
//		select_colorLED(i);
//		Delay(500);
//	}
//	
//	for(;;){
//		printf("Please press blue button.\n\r");
//		while (Button_GetState()==0);
//		srand(msTicks);               //隨機數字，需 #include <stdlib.h>
//		value = rand();
//		value= value % 8;
//		printf("value = %d \n\r",value);
//		select_colorLED(value);
//		Delay(500);
//	}	
	
	
}