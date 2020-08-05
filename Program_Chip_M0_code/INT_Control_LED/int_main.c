/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern void led_main(void);
extern void LedChange( uint8_t mode);
	
volatile uint32_t msTicks;         // Counter for millisecond Interval

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Key_1 1
#define Key_2 2
#define Key_3 3
#define Key_4 4
#define Key_default 10

#define AllLed_on		1
#define AllLed_off	2
#define OddLed_on		3
#define EvenLed_on	4
#define BitLed_on		5

volatile uint8_t key_number;

/*--------------------------------------------------------------------------------*/
// SysTick Interrupt Handler
/*--------------------------------------------------------------------------------*/
void SysTick_Handler (void) 
{       
    msTicks++;           // Increment Counter
}







/*--------------------------------------------------------------------------------*/
// Delay: delay a number of Systicks
/*--------------------------------------------------------------------------------*/
void Delay(uint32_t dlyTicks){
	uint32_t currentTicks;
	
	currentTicks = msTicks;
	while( (msTicks - currentTicks) < dlyTicks ){
		  __NOP();
	}
}

/**-----------------------------------------------------------------------------
  * @brief  Configures the System clock frequency, AHB/APBx prescalers and Flash
  *         settings.
  * @note   This function should be called only once the RCC clock configuration
  *         is reset to the default reset state (done in SystemInit() function).
  * @param  None
  * @retval None
--------------------------------------------------------------------------------  */
static void SetSysClock(void)
{
	SystemCoreClock = 48000000;
  /* SYSCLK, HCLK, PCLK configuration ----------------------------------------*/

  /* At this stage the HSI is already enabled */

  /* Enable Prefetch Buffer and set Flash Latency */
  FLASH->ACR = FLASH_ACR_PRFTBE | FLASH_ACR_LATENCY;
 
  /* HCLK = SYSCLK */
  RCC->CFGR |= (uint32_t)RCC_CFGR_HPRE_DIV1;
      
  /* PCLK = HCLK */
  RCC->CFGR |= (uint32_t)RCC_CFGR_PPRE_DIV1;

  /* PLL configuration = (HSI/2) * 12 = ~48 MHz */
  RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_PLLSRC | RCC_CFGR_PLLMUL));
  RCC->CFGR |= (uint32_t)(RCC_CFGR_PLLSRC_HSI_DIV2 | RCC_CFGR_PLLMUL12);
            
  /* Enable PLL */
  RCC->CR |= RCC_CR_PLLON;

  /* Wait till PLL is ready */
  while((RCC->CR & RCC_CR_PLLRDY) == 0)
  {
  }

  /* Select PLL as system clock source */
  RCC->CFGR &= (uint32_t)((uint32_t)~(RCC_CFGR_SW));
  RCC->CFGR |= (uint32_t)RCC_CFGR_SW_PLL;    

  /* Wait till PLL is used as system clock source */
  while ((RCC->CFGR & (uint32_t)RCC_CFGR_SWS) != (uint32_t)RCC_CFGR_SWS_PLL)
  {
  }
}
		


/*--------------------------------------------------------------------------------*/
// Button_Init(void)        ;Initialize button
// PC.13 to control User botton, set PC.13 is input pin 
/*--------------------------------------------------------------------------------*/
void Button_Init(void) {

  RCC->AHBENR |=  (1ul << 19);                  // Enable GPIOC clock       
  GPIOC->MODER &= ~(3ul << 2*13);               // Set PC.13 is input  
   
}

/*------------------------------------------------------------------------------*/
//uint32_t Button_GetState(void)
// Get USER button (PC.13) state
// return: 1 means USER key pressed
/*------------------------------------------------------------------------------*/
uint32_t Button_GetState (void) {

  uint32_t val = 0;

  if ((GPIOC->IDR & (1ul << 13)) == 0) {         //When USER button pressed PC.13=0
    val |= USER;                                 // set USER button pressed
  }
  return (val);

}

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
		}
		EXTI->PR |= 0x1ul;                 //中斷一定要清除
	}
	
	if ( (prValue & (0x1ul << 1) ) != 0)
	{	
		if  ( (GPIOA->IDR & (0x1ul << 1) ) ==0)
		{
			key_number = Key_2;
			printf("PA.1 int. \n\r");
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
		}
	}	
	EXTI->PR |= 0x1ul << 5;                 //中斷一定要清除
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
  SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_PA0PA1();
	Config_PB3PB5();
	
	led_main();
	
	key_number = Key_default;
		
	for (;;){           //CPU idle
		
		switch(key_number){
			case Key_1:
				LedChange(AllLed_on);
			break;
			case Key_2:
				LedChange(AllLed_off);
			break;
			case Key_3:
				LedChange(OddLed_on);
			break;
			case Key_4:
				//LedChange(EvenLed_on);
			LedChange(BitLed_on);
			break;
		
		
		}
	}
	
	
	
}