/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <string.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern void led_main (void);
extern void LedChange(uint8_t mode);
extern void color_led_main (void);
extern void select_colorLED(uint8_t color);

extern void melody_main (void);
extern void PlayMelody(uint8_t song_number);
extern void PWMPA4_disable(void);
extern volatile uint8_t melody_number;

extern void temp_main (void) ;
extern void Get_TempHumd(void);


extern char tempString[6];
extern char humdString[6];
	
volatile uint8_t key_number;

volatile uint32_t msTicks;         // Counter for millisecond Interval

uint32_t Tx_complete, send_length, string_length;

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Lamp1_on   'x'
#define Lamp1_off  'y'
#define Lamp2_on   'c'
#define Lamp2_off  'd'
#define Lamp3_on   'h'
#define Lamp3_off  'i'
#define Fan1_on    'k'
#define Fan1_off   'j'
#define Fan2_on    'm'
#define Fan2_off   'n'

#define Song_off_cmd   '0'
#define Song_1_cmd     '1'
#define Song_2_cmd     '2'
#define Song_3_cmd     '3'
#define Song_4_cmd     '4'
#define Song_5_cmd     '5'

#define Get_temp   't'
#define Get_hum    'u'

#define AllLed_on   1
#define AllLed_off  2
#define OddLed_on   3
#define EvenLed_on  4 
#define BitLed_on   5

#define soundStop 150
#define Song_off 0
#define Song_1   1
#define Song_2   2
#define Song_3   3
#define Song_4   4
#define Song_5   5
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

//--------------------------------------------
void Config_PA910(void) {
	RCC->AHBENR |= 0x1ul << 17;
	GPIOA->AFR[1] &= ~(0xful << 1*4 |0xful << 2*4);
	GPIOA->AFR[1] |= (0x1ul << 1*4 |0x1ul << 2*4);
	GPIOA->MODER &= ~ (0x3ul << 9*2 | 0x3ul << 10*2);
	GPIOA->MODER |= 0x2ul << 9*2 | 0x2ul << 10*2;
}	

//----------------------------------------------------------
void Send_String(char *ptr){
	
	Tx_complete = 0;
	send_length = 0;
	string_length = strlen(ptr);                // 需 #include <string.h>
	printf("length = %d. \n\r", string_length);
	
	do {
		if (send_length ==  string_length){
			Tx_complete = 1;
		} else if (USART1->ISR & (0x1ul << 7) ){
			USART1->TDR = *ptr;
			ptr++;
			send_length++;
		}
	} while (Tx_complete == 0);	
}
//---------------------------------------------------
void Config_uart1(void) {
	RCC->APB2ENR |= 0x1ul << 14;
	USART1->BRR = 48000000/115200;
	USART1->CR3 |= 0x1ul << 12;
	
	USART1->CR1 |= 0x1ul | 0x1ul << 2 | 0x1ul << 5;
	USART1->ICR |= 0x1ul << 6;
	USART1->CR1 |= 0x1ul << 3 | 0x1ul << 6;
	
	NVIC_SetPriority(USART1_IRQn,3);
	NVIC_EnableIRQ(USART1_IRQn);
}

//-----------------------------------------
void USART1_IRQHandler(void) {
	
	uint8_t data;
	
	if ( (USART1->ISR & (0x1ul << 6) ) == (0x1ul << 6) ){
		USART1->ICR |= 0x1ul << 6;             //已送完資料，清除
		if (send_length == string_length)
			Tx_complete = 1;
	}
	
	if((USART1->ISR &(0x1ul << 5))== (0x1ul << 5)) {
		data = (uint8_t) USART1->RDR;
		USART2->TDR = data;	
	
	
	switch(data) {
		case Lamp1_on:
			LedChange(AllLed_on);
		    break;
		case Lamp1_off:
			LedChange(AllLed_off);
		    break;
		case Lamp2_on:
			LedChange(OddLed_on);
		    break;
		case Lamp2_off:
			LedChange(EvenLed_on);
		    break;
		case Lamp3_on:
			select_colorLED(6);     
		    break;
		case Lamp3_off:
			select_colorLED(7);      // 暗  
		    break;
		case Fan1_on:
			select_colorLED(3);
		    break;		
		case Fan1_off:
			select_colorLED(7);
		    break;			
		case Fan2_on:
			select_colorLED(5);
		    break;		
		case Fan2_off:
			select_colorLED(7);
		    break;	
		case Song_1_cmd:
			melody_number = Song_1;
			break;
		case Song_2_cmd:
			melody_number = Song_2;
			break;
		case Song_3_cmd:
			melody_number = Song_3;
			break;
		case Song_4_cmd:
			melody_number = Song_4;
			break;
		case Song_5_cmd:
			melody_number = Song_5;
			break;
		case Song_off_cmd:
			melody_number = Song_off;
			break;		
		case Get_hum:
			Get_TempHumd();
			Send_String(humdString);
			break;		
		case Get_temp:
			Get_TempHumd();
			Send_String(tempString);
			break;
		}	
	}
}	


/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
	/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
    SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	NVIC_SetPriority(SysTick_IRQn,0);
	
	Config_PA910();
	Config_uart1();
	led_main();
	color_led_main();
	select_colorLED(7);                       //暗
	melody_main();
	temp_main();
	
	for (;;) {
		switch(melody_number){
			case Song_off:
				PWMPA4_disable();            //聲音關
				break;
			case Song_1:
				PlayMelody(Song_1);
				break;
			case Song_2:
				PlayMelody(Song_2);          //happy birthday
				break;
			case Song_3:
				PlayMelody(Song_3);          //little star  
				break;
			case Song_4:
				PlayMelody(Song_4);          //little bee
				break;
			
			case Song_5:
				PlayMelody(Song_5);          //little bee
				break;
		}
	}	
}