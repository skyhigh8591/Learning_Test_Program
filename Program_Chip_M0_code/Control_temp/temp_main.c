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

char tempString[6];
char humdStrimg[6];

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
//-------------------------------------------------------------
void Config_PA12(void)
{
	RCC->AHBENR |= 0x1ul <<17;
	GPIOA->MODER &= ~ (0x3ul<< 12*2);
	GPIOA->MODER |= 0x1ul<< 12*2;
	
	GPIOA->OSPEEDR &= ~(0x3ul << 12*2);
	GPIOA->OSPEEDR |=0x1ul<<12*2;
	
}

void Set_high(void)
{
	GPIOA->ODR |= 0x1ul << 12;
}

void Set_low(void)
{
	GPIOA->ODR &= ~ (0x1ul << 12);
}

void Set_output(void)
{
	GPIOA->MODER |= 0x1ul << 12*2;
}

void Set_input(void)
{
	GPIOA->MODER &= ~ (0x3ul << 12*2);
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
	uint32_t startTick,pulseWidth;
	uint32_t data[43];
	uint32_t dataValue,humData,tempData,parityData;
	uint32_t calParity,calData;
	uint32_t tempValue,HumdValue;
	float tempReal,humdReal;
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
  SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	Config_PA12();
	Button_Init();
	
	for(;;){
		
		printf("Please press bule key.\n\r");
		while(Button_GetState()==0);
		Delay(1000);
		Set_output();
		Set_high();
		Delay(5);
		startTick = msTicks;
		Set_low();
		Delay(5);
		Set_high();
		
		Set_input();
		
		for(int i=0;i<42;i++)
		{
			pulseWidth=0;
			while((GPIOA->IDR & (0x1ul<<12))==0){
				pulseWidth++;
				if((msTicks - startTick)>500)
					break;
			}
			
			while((GPIOA->IDR & (0x1ul<<12))==(0x1ul<<12)){
				pulseWidth++;
				if((msTicks-startTick)>500)
				break;
			}
			
			data[i]=pulseWidth;
			
		}
		
		for(int i=0 ; i < 42 ; i++){
		printf("data value %d = %d \n\r",i,data[i]);
		}
		
		dataValue = 0;
		parityData = 0;
		for(int i = 2;i<42;i++){
		
			if(i<34){
				if(data[i]>190)
					dataValue |=0x1ul;
				
				if(i<33)
					dataValue = dataValue << 1;
			
			}else{
			
				if(data[i]>190)
					parityData |= 0x1ul;
				
				if(i<41)
					parityData = parityData<<1;
			
			}
		
		}
		
		printf("data value = %x.\n\r",dataValue);
		printf("parity value = %x.\n\r",parityData);
	
		
		
		calData = dataValue;
		calParity = 0;
		for(int i = 0 ; i<4 ; i++){
			calParity=calParity+(calData&0xff);
			calData=calData>>8;
			
		}
		printf("parity data = %x.\n\r",calParity);
		if(calParity==parityData){
			tempValue = dataValue & 0xfffful;
			HumdValue = (dataValue >> 16) & 0xfffful;
			tempReal = tempValue / 10.0;
			printf("temp value = %f.\n\r",tempReal);
			humdReal = HumdValue/10.0;
			printf("humdReal value = %f.\n\r",humdReal);
			
			sprintf(tempString,"%f",tempReal);
			sprintf(humdStrimg,"%f",humdReal);
			printf("temp string = %s.\n\r",tempString);
			printf("humd string = %s.\n\r",humdStrimg);
			
		}else{
			printf("Parity check error.\n\r");
		}
		
	}
	
	
	
}