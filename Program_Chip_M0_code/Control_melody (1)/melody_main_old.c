/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);

volatile uint32_t msTicks;         // Counter for millisecond Interval
volatile uint32_t Tim2_Ticks;   

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

//-------------------------------------------------
void Config_Timer2(void)
{
	RCC->APB1ENR |= 0x1ul;
	
	TIM2->PSC = 48-1;      
	TIM2->ARR = 1000-1;
	TIM2->CNT = 0;
	TIM2->CR1 |= 0x1ul << 7 | 0x1ul;
	TIM2->DIER |= 0x1ul;
	
	NVIC_SetPriority(TIM2_IRQn, 3);
	NVIC_EnableIRQ(TIM2_IRQn);
	
}
//--------------------------
void TIM2_IRQHandler(void)
{
	Tim2_Ticks++;
    TIM2->SR &= ~ 0x1ul;
	
}

//---------------------------------------------
void TIM2Delay(uint32_t counter)
{
	uint32_t currentTicks;
	
	currentTicks=Tim2_Ticks;
	while ( (Tim2_Ticks - currentTicks) < counter){
		__NOP;
	}
}

//---------------------
void PWMPA4_init(void)
{
	RCC->AHBENR |= 0x1ul<< 17;
	GPIOA->AFR[0] &= ~(0xful << 4*4);
	GPIOA->AFR[0] |= 0x4ul << 4*4;
	
	GPIOA->MODER &= ~(0x3ul << 4*2);
	GPIOA->MODER |= 0x2ul << 4*2;
}

//----------------
void Config_timer14(void)
{
	RCC->APB1ENR |= 0x1ul << 8;
	TIM14->PSC = 480-1;
	TIM14->ARR = 100-1;                 //period
	TIM14->CCR1 = 80;         //80      //duty cycle 可控制聲音大小
	TIM14->CNT = 0;
	
	TIM14->CCMR1 |= 0x6ul << 4;         //PWM capture mode 2，0x6ul << 4   PWM capture mode 1
	TIM14->CR1 |= 0x1ul << 7;
}

//--------------------------
void PWMPA4_enable(void)
{
	TIM14->CNT = 0;       //counter
	TIM14->CR1 |= 0x1ul;
	TIM14->CCER |= 0x1ul;
}

//--------
void PWMPA4_disable(void)
{
	TIM14->CCER &= ~ 0x1ul;
	TIM14->CR1 &= ~ 0x1ul;
}

//-------------------------------------
void SelectTone(uint32_t tone_number)
{
	uint32_t ToneArr[]={1,764,681,607,573,510,454,405,  382,340,303,286,255,227,202,191,170,152,143,128,114,101};  //第一個 tone 0 (不可除) 改為 1
	uint32_t ARRValue;
		
	ARRValue = ToneArr[tone_number];
	TIM14->ARR =ARRValue;
	TIM14->CNT = 0;
	TIM14->CCR1 = ARRValue * 0.9;  //聲音大小
}

//-------------------------------
#define soundStop  150
#define Song_off 0
#define Song_1   1
#define Song_2   2
#define Song_3   3
#define Song_4   4

void PlayMelody(uint8_t song_number) 
{   
    //Basic tone	
	uint8_t note_basic[]={1,2,3,4,5,6,7,1+7,2+7,3+7,4+7,5+7,6+7,7+7,1+14,2+14,3+14,4+14,5+14,6+14,7+14}; 
	uint32_t tone, beat;	
		
	//Happy birthday
	uint8_t note_happy_song[]={5,5,6,5,1+7,7,5,5,6,5,2+7,1+7,5,5,5+7,3+7,1+7,7,6,4+7,4+7,3+7,1+7,2+7,1+7 };		
	uint16_t beat_happy_song[]={250,250,500,500,500,1000,250,250,500,500,500,1000,250,250,500,500,500,500,1500,250,250,500,500,500,1500};
	
	//Little Star Song	
	uint8_t note_little_star[]={1,1,5,5,6,6,5,4,4,3,3,2,2,1,5,5,4,4,3,3,2,5,5,4,4,3,3,2,1,1,5,5,6,6,5,4,4,3,3,2,2,1};
	uint16_t beat_little_star[]={500,500,500,500,500,500,1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,\
	1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,1000};
					
	//Little Bee Song	
	uint8_t  note_little_bee[]={5,3,3,4,2,2,1,2,3,4,5,5,5,5,3,3,4,2,2,1,3,5,5,3,2,2,2,2,2,3,4,3,3,3,3,3,4,5,5,3,3,4,2,2,1,3,5,5,1};	
	uint16_t beat_little_bee[]={250,250,500,250,250,500,250,250,250,250,250,250,500,250,250,500,250,250,500,250,250,250,250,1000,\
						250,250,250,250,250,250,500,250,250,250,250,250,250,500,250,250,500,250,250,500,250,250,250,250,1000};	

	
	PWMPA4_enable();		
	switch(song_number){
		case Song_1:
			for (int i=0 ; i<sizeof(note_basic);i++){
				tone = note_basic[i];
				SelectTone(tone);
				TIM2Delay(500);   //1拍 500 ms
				PWMPA4_disable();
				TIM2Delay(soundStop);
				PWMPA4_enable();
			}
			
			break;
		case Song_2:
			for (int i=0 ; i<sizeof(note_happy_song);i++){
				tone = note_happy_song[i];
				tone += 7;
				SelectTone(tone);
				beat = beat_happy_song[i];
				beat = beat- 50;
				TIM2Delay(beat);   //1拍 500 ms
				PWMPA4_disable();
				TIM2Delay(soundStop);
				PWMPA4_enable();
			}	
			break;		
		case Song_3:
			for (int i=0 ; i<sizeof(note_little_star);i++){
				tone = note_little_star[i];
				SelectTone(tone);
				beat = beat_little_star[i];
				beat = beat- 50;
				TIM2Delay(beat);   //1拍 500 ms
				PWMPA4_disable();
				TIM2Delay(soundStop);
				PWMPA4_enable();
			}		
			break;
		case Song_4:
			for (int i=0 ; i<sizeof(note_little_bee);i++){
				tone = note_little_bee[i];
				SelectTone(tone);
				beat = beat_little_bee[i];
				beat = beat- 50;
				TIM2Delay(beat);   //1拍 500 ms
				PWMPA4_disable();
				TIM2Delay(soundStop);
				PWMPA4_enable();
			}		
			
			break;		
	}
	PWMPA4_disable();
}
/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) 
{        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
    SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_Timer2();
	PWMPA4_init();
	Config_timer14();

//	PWMPA4_enable();
//	PlayMelody(Song_1);
//	TIM2Delay(2000);
	PlayMelody(Song_2);
	TIM2Delay(2000);
	
	
	
//	TIM2Delay(3000);
//	PWMPA4_disable();
//-----------------------	
//	TIM14->ARR = 100000/262-1;                 //period
//	PWMPA4_enable();
//	TIM2Delay(1000);
//	PWMPA4_disable();
//	TIM2Delay(1000);
//	
//	TIM14->ARR = 100000/294-1;                 //period
//	PWMPA4_enable();
//	TIM2Delay(1000);
//	PWMPA4_disable();
//	TIM2Delay(1000);

//	TIM14->ARR = 100000/330-1;                 //period
//	PWMPA4_enable();
//	TIM2Delay(1000);
//	PWMPA4_disable();
//	TIM2Delay(1000);
//	
//	ARR =value1;
//	EnablePWM();
//	TIM2Delay(1000);
//	DisablePWM();
//	TIM2Delay(1000);
//	
//	ARR = value2;
//	EnablePWM();
//	TIM2Delay(1000);
//	DisablePWM();
//	TIM2Delay(1000);
	
	
	
//-------------------------------------	
	for(;;){
		printf("timer 2 delay. \n\r");         //因 Timer 2，每 2秒 會顯示 "timer 2 delay" 1次.
		TIM2Delay(2000);
	}
		
}