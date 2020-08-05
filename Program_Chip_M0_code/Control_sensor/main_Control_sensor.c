/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);

volatile uint32_t msTicks;         // Counter for millisecond Interval
volatile uint32_t Tim6_Tick;

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

volatile uint32_t ADCValue[5];

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

//-------------------------------------------------
void Config_PC0123 (void)
	
{
	RCC->AHBENR |= 0x1ul << 19 ;	
	GPIOC->MODER |= 0xfful ;	
}

//-------------------------------------------------
void Config_PB1 (void)
	
{
	RCC->AHBENR |= 0x1ul << 18 ;	
	GPIOB->MODER |= 0x3ul<< 1*2 ;	
}

//----------------------------------------------------
void Config_ADC(void)
	
{
	RCC->APB2ENR |= 0x1ul << 9 ;
	
	RCC->CR2 |= 0x1ul ;//打開需要時間 
	while((RCC ->CR2 & (0x1ul <<1 )) == 0);  //請確認1bit 是否為1 代表打開完成
	
	ADC1->CR |= 0x1ul << 31 ;
	while( (ADC1 -> CR &(0x1ul << 31 ) ) == (0x1ul <<31) );  //等他自動校準
	
	ADC1->CFGR2 &= ~(0x3ul << 30);  //00: ADCCLK (Asynchronous clock mode), generated at product level (refer to RCC section)
	ADC1->CFGR1 &= ~(0x1ul<<13);    //選擇單獨
	
	ADC1->CFGR1 &= ~(0x3ul << 3 );//解析度
	ADC1->CFGR1 |= 0x1ul << 3 ;
	
	ADC1->CHSELR |= 0xful << 10 | 0x1ul << 9 ;  //打開Channal  9 - 13
	ADC1->SMPR &= ~(0x7ul);//取樣頻率速度
	ADC1->SMPR |= 0x4ul;
	
	ADC1->CR |= 0x1ul ;
	while( (ADC1->ISR & 0x1ul ) ==0);   //等他打開ADC
	
}

//----------------------
void Config_timer7(void)
{
	RCC->APB1ENR |= 0x1ul <<5;
	TIM7->PSC =4800-1;
	TIM7->ARR =2000-1;
	TIM7->CNT=0;
	
	TIM7->CR1 |= 0x1ul  << 7 | 0x1ul;
	TIM7->DIER |= 0x1ul;
	
	NVIC_SetPriority (TIM7_IRQn,2);
	NVIC_EnableIRQ(TIM7_IRQn);
}
//---------------
void TIM7_IRQHandler (void) 
{
	GPIOB->ODR |= 0x1ul;
	for (int i=0 ; i<5 ; i++)
		__NOP;
	
	GPIOB->ODR &= ~ 0x1ul;
	
    
		ADC1->CR |= 0x1ul << 2;
		for(int i =0 ; i<5 ; i++)
		{
			while ((ADC1->ISR & (0x1ul << 2) ) == 0);
			ADCValue[i]=ADC1->DR;			
		}
		
//		printf("PB.1 adc value = %d \n\r",ADCValue[0]);
//		printf("PC.0 adc value = %d \n\r",ADCValue[1]);
//		printf("PC.1 adc value = %d \n\r",ADCValue[2]);
//		printf("PC.2 adc value = %d \n\r",ADCValue[3]);
//		printf("PC.3 adc value = %d \n\r",ADCValue[4]);
		
//		if( ADCValue[0] > 650) {
//			printf("PB.1 adc value = %d \n\r",ADCValue[0]);
//		}
//		
//		if(ADCValue[1]<700 || ADCValue[2]<700){
//			printf("PC.0 adc value = %d \n\r",ADCValue[1]);
//			printf("PC.1 adc value = %d \n\r",ADCValue[2]);
//		}
		
//		if(ADCValue[3]<700 || ADCValue[4]<700){
//			printf("PC.2 adc value = %d \n\r",ADCValue[3]);
//			printf("PC.3 adc value = %d \n\r",ADCValue[4]);
//		}
		TIM7->SR &= ~ 0x1ul;
}		
//--------------------------------------
void Config_PB0(void)
{
	RCC->AHBENR |= 0x1ul <<18;
	GPIOB->MODER &= ~ 0x3ul;
	GPIOB->MODER |= 0x1ul;
	
	
}
//----------------------
void Config_PB2(void)
{
	RCC->AHBENR |= 0x1ul << 18;
	GPIOB->MODER &= ~ (0x3ul << 2*2);
	RCC->APB2ENR |= 0x1ul;
	SYSCFG->EXTICR[0] &=  ~( 0xful << 2*4);
	SYSCFG->EXTICR[0] |= 0x1ul << 2*4;
	
	EXTI->FTSR |= 0x1ul << 2;
	EXTI->RTSR |= 0x1ul << 2;
	EXTI->IMR |= 0x1ul << 2;
	EXTI->PR |= 0x1ul << 2;
	
	NVIC_SetPriority (EXTI2_3_IRQn,2);
	NVIC_EnableIRQ(EXTI2_3_IRQn);
	
}
//------------------------
void EXTI2_3_IRQHandler(void)
{
	uint32_t currentTick, range;

	if ((EXTI->PR & 0x1ul <<2)  == (0x1ul << 2)){
		if ((GPIOB->IDR & (0x1ul << 2)) == (0x1ul <<2)){
			Tim6_Tick=0;
			printf("pb2 start.\n\r");
		}else{
			printf("pb2 end.\n\r");
			currentTick=Tim6_Tick;
			range = (currentTick * 34)/20;
			printf("time = %d \n\r", currentTick);
			printf("range = %d cm\n\r", range);	
			
		}			
	}
	EXTI->PR |= 0x1ul <<2;
}
//------------------------
void Config_timer6(void)
{
	RCC->APB1ENR |= 0x1ul << 4;
	TIM6->PSC =48-1;               //100us
	TIM6->ARR =100-1;
	TIM6->CNT=0;
	
	TIM6->CR1 |= 0x1ul  << 7 | 0x1ul;
	TIM6->DIER |= 0x1ul;
	
	NVIC_SetPriority (TIM6_IRQn,2);
	NVIC_EnableIRQ(TIM6_IRQn);
}

//-------------
void TIM6_DAC_IRQHandler(void)
{
	Tim6_Tick++;
	TIM6->SR &= ~ 0x1ul;
	
}	
/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
    SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_PB1();
	Config_PC0123();
	Config_ADC();
	Config_PB0();
	Config_PB2();
	Config_timer6();
	Config_timer7();

	
	for(;;)
	
	{

		//printf("PC.0 adc value = %d \n\r",ADCValue[1]);
		
//		printf("PB.1 adc value = %d \n\r",ADCValue[0]);
//		printf("PC.0 adc value = %d \n\r",ADCValue[1]);
//		printf("PC.1 adc value = %d \n\r",ADCValue[2]);
//		printf("PC.2 adc value = %d \n\r",ADCValue[3]);
//		printf("PC.3 adc value = %d \n\r",ADCValue[4]);
		
//		Delay(3000);
	
		
	}
	
	
	
	
}