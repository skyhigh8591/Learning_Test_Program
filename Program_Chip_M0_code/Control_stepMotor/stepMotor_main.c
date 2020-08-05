/**   Project name : 
* 四相步進馬達轉1圈 360/(5.625/64)=4096步
rpm(resolution per minuts)每分鐘轉速 4096步，
每步時間 60*10^3/4096=14.65ms，14.65ms/0.1ms(中斷)=146個 delay
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);

extern void setRpm(uint32_t rpm);
extern void Config_TIM7(void);
extern void TIM7_IRQHandler(void);

extern void motorDelay(uint32_t delay);
	
extern void setValue(int index);
extern void moveCW(void);
extern void moveCCW(void);
extern void stopMotor(void);

extern void motor_moveStep(uint8_t clockwise, uint32_t numStep);
extern void motor_moveDegree(uint8_t clockwise,uint32_t degree);

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
//---------------------------------------------------------------------------------
void Config_PC0123 (void)
{
	RCC->AHBENR |= 0x01 << 19;
	GPIOC->MODER &= ~ (0xfful);
	GPIOC->MODER |= 0x055ul;
	GPIOC->OSPEEDR &= ~ (0xfful);
	GPIOC->OSPEEDR |= 0x055ul;
}

//----------------------------------------------------------


/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
    SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_PC0123();
	Button_Init();
	Config_TIM7();
	
	printf ("rpm = 1\n\r");
	setRpm(1);
	motor_moveStep(1,500);     //正轉
	Delay(1000);
	
	printf ("rpm = 2\n\r");
	setRpm(2);
	motor_moveStep(2,500);     //反轉
	Delay(1000);
	
	printf ("rpm = 3\n\r");
	setRpm(3);
	motor_moveStep(1,1000);
	Delay(1000);
	
	printf ("rpm = 4\n\r");
	setRpm(4);
	motor_moveStep(2,1000);
	Delay(1000);
	
	printf ("rpm = 15\n\r");
	setRpm(15);
	motor_moveStep(1,3000);
	Delay(1000);

	printf ("rpm = 16\n\r");
	setRpm(16);
	motor_moveStep(1,3000);
	Delay(1000);

	printf ("rpm = 17\n\r");
	setRpm(17);
	motor_moveStep(1,3000);
	Delay(1000);

	printf ("rpm = 18\n\r");
	setRpm(18);
	motor_moveStep(1,3000);
	Delay(1000);
	
	printf ("rpm = 10\n\r");
	setRpm(10);
	motor_moveStep(1,270);
	Delay(1000);
	
	printf ("rpm = 12\n\r");
	setRpm(12);
	motor_moveStep(0,600);
	Delay(1000);
	
	stopMotor();

	
	for(;;)
	{
	
	}
	
	
}