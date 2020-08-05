/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);

volatile uint32_t msTicks;         // Counter for millisecond Interval
volatile uint32_t TIM6_Ticks;
volatile uint32_t current_Tim6;
volatile uint8_t  PB2_flag;

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

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
//----------------------------------------------------------------------------
void Config_PB2(void)
{
	RCC->AHBENR |= 0x1ul <<18;
	GPIOB->MODER &=~(0x3ul << 2*2);
	
	RCC->APB2ENR |= 0x1ul;
	SYSCFG->EXTICR[0] &= ~(0xful << 2*4);
	SYSCFG->EXTICR[0] |= 0x1ul << 2*4;
	
	EXTI->FTSR |= 0x1ul <<2;
	EXTI->RTSR |= 0x1ul <<2;
	EXTI->IMR  |= 0x1ul	<<2;
	
	EXTI->PR   |= 0x1ul <<2;
	
	NVIC_SetPriority(EXTI2_3_IRQn,3);
	NVIC_EnableIRQ(EXTI2_3_IRQn);
}
//----------------------------------------------------------------
//void EXTI2_3_IRQHandler(void)
//{
//	printf("PB2 int.\n\r");
//	
//	EXTI->PR |= 0x1ul << 2;
//	
//}
//----------------------------------------------------------------
void Config_Timer6(void)
{
	RCC->APB1ENR |= 0x1ul << 4;
	
	TIM6->PSC = 4800 -1;
	TIM6->ARR = 1000 -1;
	TIM6->CNT = 0;
	TIM6->CR1 |= 0x1ul;
	TIM6->DIER |= 0x1ul;
	
	NVIC_SetPriority(TIM6_IRQn,2);
	NVIC_EnableIRQ(TIM6_IRQn);
	
}
//------------------------------------------------------------------
void TIM6_DAC_IRQHandler(void)
{
	TIM6_Ticks++;
	TIM6->SR &=~ 0x1ul;
//	printf("timer 6");
}
//-----------------------------------------------------------------
void PA5_init(void)
{
	RCC->AHBENR |= 0x1ul << 17;
	GPIOA->MODER &= ~(0x3ul << 5*2);
	GPIOA->MODER |=0x1ul << 5*2;
}

void PA5_on(void)
{
	GPIOA->ODR |=0x1ul <<5;
}
//-----------------------------------------------------
void PA5_off(void)
{
	GPIOA->ODR &= ~(0x1ul << 5);
}
//----------------------------------------------
void EXTI2_3_IRQHandler(void)
{
	uint32_t time;
	if(EXTI->PR & (0x1ul<<2)){
		if((GPIOB->IDR & (0x1ul<<2))==(0x1ul<<2)){
				printf("PB2 int.\n\r");
				current_Tim6 = TIM6_Ticks;
				PB2_flag = 1;
		}else{
			if(PB2_flag==1){
				time = (TIM6_Ticks - current_Tim6)* 0.1;
				printf("time = %d\n\r",time);
				PB2_flag = 0;
			}
		}
		EXTI->PR |=0x1ul <<2;
	}
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void){        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
		SetSysClock();
		
		stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
																									
		SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
		
		Config_PB2();
		Config_Timer6();
		
		PA5_init();
		PA5_on();
		Delay(1000);
		PA5_off();
		
		for(;;)
		{
			
		}
}
