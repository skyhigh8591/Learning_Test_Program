/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);

volatile uint32_t msTicks;         // Counter for millisecond Interval

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

/*--------------------------------------------------------------------------------*/

void GPIOCO_7_init(void)
{
	RCC->AHBENR |=0x1ul << 19;
	
	GPIOC->MODER &= ~(0xfffful);
	GPIOC->MODER |= 0x5555ul;
	
	GPIOC->OSPEEDR &= ~0xfffful;
	GPIOC->OSPEEDR |=0x5555ul;
	
	
}
#define AllLed_on		1
#define AllLed_off	2
#define OddLed_on		3
#define EvenLed_on	4
#define BitLed_on		5

void LedChange( uint8_t mode)
{
	uint32_t bitValue;
	uint32_t currtValue; 
	switch(mode){
		case AllLed_on:
			
			GPIOC->ODR |=   0xfful;
			Delay(1000);
		break;
		case AllLed_off:
			
			GPIOC->ODR &= ~0xfful;
		//	GPIOC->ODR &= ~0xfffff00;
			Delay(1000);
	
		
		break;
		case OddLed_on:
		GPIOC->ODR &= ~0xfful;
		GPIOC->ODR |= 0xAAul;
		break;
		case EvenLed_on:
		GPIOC->ODR &= ~0xfful;
		GPIOC->ODR |= 0x55ul;
		break;
		case BitLed_on:
			GPIOC->ODR &= ~0xfful;
			currtValue = 1;
			for(int i=0; i<8 ; i++){
				bitValue = 0x1ul;
				bitValue =  bitValue << i;
				GPIOC->ODR &= ~ currtValue;
				GPIOC->ODR |= bitValue;
				currtValue = bitValue;
				Delay(1000);
			}
			
		
		break;
		
	}
}


// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
  SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	GPIOCO_7_init();
	
	for(;;){
	//GPIOC->ODR |=   0xfful;
	//Delay(1000);
	//GPIOC->ODR &= ~0xfful;
	//Delay(1000);	
		
		LedChange(AllLed_on);
		Delay(1000);
		LedChange(AllLed_off);
		Delay(1000);
		LedChange(OddLed_on);
		Delay(1000);
		LedChange(EvenLed_on);
		Delay(1000);
		LedChange(AllLed_off);
		Delay(1000);
		
		LedChange(BitLed_on);
		Delay(1000);
		LedChange(AllLed_off);
		Delay(1000);
		
	
	}
	
	
}