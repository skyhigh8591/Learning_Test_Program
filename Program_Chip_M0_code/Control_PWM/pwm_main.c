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
//----------------------------------------------------
void Config_PC89(void)
{
	RCC->AHBENR |= 0x1ul << 19;
	GPIOC->AFR[1] &= ~(0xful | 0xful << 1*4);           //TIM3
	GPIOC->MODER &= ~(0x3ul << 8*2 | 0x3ul << 9*2);
	GPIOC->MODER |= 0x2ul << 8*2 | 0x2ul << 9*2;
}	

//-----------------------------------------------------
void Config_PC7(void)
{
	RCC->AHBENR |= 0x1ul << 19;
	GPIOC->AFR[0] &= ~(0xful << 7*4);                  //TIM3
	GPIOC->MODER &= ~(0x3ul << 7*2 );                  //clr
	GPIOC->MODER |= 0x2ul << 7*2;                      //set
}

//---------------------------------------------------
void Config_Tim3(void)
{
	RCC->APB1ENR |= 0x1ul << 1;                     // enable TIM3 clK
	
	TIM3->PSC = 4800 -1;
	TIM3->ARR = 400 -1;	                           //40ms
	TIM3->CCR1 = 0;
	TIM3->CCR2 = 0;	
	TIM3->CCR3 = 0;
	TIM3->CCR4 = 0;
	
	TIM3->CNT = 0;
	TIM3->CCMR1 = 0x6ul << 12;
	TIM3->CCMR2 = 0x6ul << 4 | 0x6ul << 12;	
}

//-----------------------------------
void EnablePWM_Ch2(void)
{
	TIM3->CNT = 0;    //counter
	TIM3->CCER |= 0x1ul << 4;
	TIM3->CR1 |= 0x1ul;
}
//-------------------------------------
void DisablePWM_Ch2(void)
{
	TIM3->CCER &= ~ ( 0x1ul << 4);   //clr
	TIM3->CR1 &= ~ 0x1ul;
}

//-----------------------------------
void EnablePWM_Ch3(void)
{
	TIM3->CNT = 0;    //counter
	TIM3->CCER |= 0x1ul << 8;
	TIM3->CR1 |= 0x1ul;
}
//-------------------------------------
void DisablePWM_Ch3(void)
{
	TIM3->CCER &= ~ ( 0x1ul << 8);   //clr
	TIM3->CR1 &= ~ 0x1ul;
}

//-----------------------------------
void EnablePWM_Ch4(void)
{
	TIM3->CNT = 0;    //counter
	TIM3->CCER |= 0x1ul << 12;
	TIM3->CR1 |= 0x1ul;
}
//-------------------------------------
void DisablePWM_Ch4(void)
{
	TIM3->CCER &= ~ ( 0x1ul << 12);   //clr
	TIM3->CR1 &= ~ 0x1ul;
}

//----------------------
void ChangePWMValue_Ch2 (uint32_t value)
{
	TIM3->CCR2 = value;
}

//----------------------
void ChangePWMValue_Ch3 (uint32_t value)
{
	TIM3->CCR3 = value;
}

//----------------------
void ChangePWMValue_Ch4 (uint32_t value)
{
	TIM3->CCR4 = value;
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
  SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_PC7();
	Config_PC89();
	Config_Tim3();
	
	EnablePWM_Ch2();
	for (int i=5; i<25; i++){
		ChangePWMValue_Ch2(i);
		Delay(300);
	}
	ChangePWMValue_Ch2(5);
	Delay(1000);
	DisablePWM_Ch2();
	
	EnablePWM_Ch3();
	for (int i=5; i<25; i++){
		ChangePWMValue_Ch3(i);
		Delay(300);
	}
	ChangePWMValue_Ch3(5);
	Delay(1000);
	DisablePWM_Ch3();
	
	EnablePWM_Ch4();
	for (int i=5; i<25; i++){
		ChangePWMValue_Ch4(i);
		Delay(300);
	}
	ChangePWMValue_Ch4(5);
	Delay(1000);
	DisablePWM_Ch4();
	 
	for (;;){ }
	
}