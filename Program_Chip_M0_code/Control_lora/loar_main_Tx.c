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

#define maxValue     50
volatile char receive_buffer[maxValue];
volatile uint8_t receive_index, sendLength,sendCount;
volatile uint8_t receiveCompleteFlag, transmitCompleteFlag;

const char nAT_1[]="AT\r\n";
const char nATReset_2[]="AT+RESET\r\n";
const char nATMode_3[]="AT+MODE?\r\n";
const char nATVersion_13[]="AT+VER?\r\n";
const char nATUart_4[]="AT+IPR?\r\n";

const char nATParameter_Set5[]="AT+PARAMETER=10,7,1,7\r\n"; 
const char nATParameter_5[]="AT+PARAMETER?\r\n"; 
const char nATBand_Set6[]="AT+BAND=868500000\r\n";
const char nATBand_6[]="AT+BAND?\r\n";
const char nATAddress_Set7[]="AT+ADDRESS=105\r\n";
const char nATAddress_7[]="AT+ADDRESS?\r\n";

const char nATNetworkID_Set8[]="AT+NETWORKID=5\r\n";
const char nATNetworkID_8[]="AT+NETWORKID?\r\n";

const char nATCpin_Set9[]="AT+CPIN=0123456789ABCDEF0123456789abcdef\r\n";
const char nATCpin_9[]="AT+CPIN?\r\n";

const char nATCRFOP_Set10[]="AT+CRFOP=12\r\n";
const char nATCRFOP_10[]="AT+CRFOP?\r\n";

const char nATSend_1[]="AT+SEND=112,2,on\r\n";   //on 2個字
const char nATSend_2[]="AT+SEND=101,6,Taiwan\r\n";   //Taiwan 6個字

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
//---------------------------------------
void  Config_PA56(void)
{
	RCC->AHBENR |=0x01ul << 17;
	GPIOA->MODER &= ~(0x3ul << 5*2 | 0x3ul << 6*2);
	GPIOA->MODER |= 0x1ul << 5*2 | 0x1ul << 6*2;
	
	GPIOA->OSPEEDR &= ~(0x3ul << 5*2 | 0x3ul << 6*2);
	GPIOA->OSPEEDR |= 0x1ul << 5*2 | 0x1ul << 6*2;
	
	GPIOA->ODR |= 0x1ul << 6;
}

//-----------------------------------
void led_on(void)
{
	GPIOA->ODR |= 0x1ul << 5;
}
//-------------------------------------
void led_off(void)
{
	GPIOA->ODR &= ~(0x1ul << 5);
}
//------------------------------------
void reset_Loar(void)
{
	GPIOA->ODR &= ~(0x1ul << 6);
	Delay(200);
	GPIOA->ODR |= 0x1ul << 6;	
}

//-----------------------------------------
void Config_PB1011(void)
{
	RCC->AHBENR |=0x1ul << 18;
	
	GPIOB->AFR[1] &= ~(0xful << 2*4 | 0xful <<3*4);

	GPIOB->AFR[1] |= 0x4ul << 2*4 | 0x4ul <<3*4 ;
	
	GPIOB->MODER &= ~(0x3ul << 10*2 | 0x3ul << 11*2);
	GPIOB->MODER |= 0x2ul << 10*2 | 0x2ul << 11*2;
}
//---------------------------------
void Config_Uart3(void)
{
	RCC->APB1ENR |= 0x1ul << 18;
	
	USART3->BRR = 48000000/115200;
	USART3->CR3 |= 0x1ul << 12;
	USART3->CR1 |= 0x1ul << 5 | 0x1ul << 2 | 0x1ul;
	
	USART3->ICR |= 0x1ul << 6;
//	USART3->CR1 |= 0x1ul << 6 | 0x1ul << 3;
	USART3->CR1 |=  0x1ul << 3;
	
	NVIC_SetPriority(USART3_4_IRQn,3);
	NVIC_EnableIRQ(USART3_4_IRQn);
}
//-----------------------------------
void USART3_4_IRQHandler(void)
{
	uint8_t  charData, charNumber;  //每收1個 byte 中斷一次
	
	if ((USART3->ISR & (0x1ul << 5)) == ( 0x1ul << 5))
	{
		charData = (uint8_t) USART3->RDR;
		USART2->TDR = charData;                        //putty 接口
		receive_buffer[receive_index] = charData;
		receive_index++;
		if (receive_index>=maxValue){
			receive_index=0;
			receiveCompleteFlag=1;
		}
	}
}
//-----------------------------
void send_ATCMD(char * atPtr)
{
	transmitCompleteFlag=0;
	
	sendLength = strlen(atPtr);          //型態不對，但不影響
//	printf("AT cmd length = %d \n\r",sendLength);
	sendCount=0;
	
	do{
		if (sendCount == sendLength){
			transmitCompleteFlag=1;
			
		}else if (USART3->ISR & (0x1ul << 7)){
			USART3->TDR = * atPtr;
			atPtr++;
			sendCount++;
		}	
	}while (transmitCompleteFlag == 0);
	
}
//-----------------------------------------








/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
int main (void) {        // User application starts here
	
		/* Configure the System clock frequency, AHB/APBx prescalers and Flash settings */
    SetSysClock();
	
	stdout_init();              // Initialize USART 2(PA3 to USART2_RX,PA2 to USART2_TX)  
		                                            
	SysTick_Config(SystemCoreClock/1000);      // System Tick Initializes,set SysTick 1ms interrupt
	
	
	Config_PA56();
	Config_PB1011();
	Config_Uart3();
	
	//reset_Loar();   //reset 需時間長
	
	printf("1.AT cmd\n\r");
	receive_index=0;
	send_ATCMD((char *) nAT_1);
	Delay(1000);
	
	printf("13. AT version cmd\n\r");
	receive_index=0;
	send_ATCMD((char *) nATVersion_13);
	Delay(1000);
	
	printf("3. AT mode\n\r");
	receive_index=0;
	send_ATCMD((char *) nATMode_3);
	Delay(1000);	
	
	printf("4. AT uart mode\n\r");
	receive_index=0;
	send_ATCMD((char *) nATUart_4);
	Delay(1000);
	
	printf("5. AT RF param.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATParameter_Set5);
	Delay(1000);
	
	printf("5. AT RF param.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATParameter_5);
	Delay(1000);
	
	printf("6. AT RF band.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATBand_Set6);
	Delay(1000);	
	
	printf("6. AT RF band.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATBand_6);
	Delay(1000);	
	
	printf("7. AT Adress\n\r");
	receive_index=0;
	send_ATCMD((char *) nATAddress_Set7);
	Delay(1000);
		
	printf("7. AT Adress\n\r");
	receive_index=0;
	send_ATCMD((char *) nATAddress_7);
	Delay(1000);
	
	printf("8. AT network\n\r");
	receive_index=0;
	send_ATCMD((char *) nATNetworkID_Set8);
	Delay(1000);
	
	printf("8. AT network\n\r");
	receive_index=0;
	send_ATCMD((char *) nATNetworkID_8);
	Delay(1000);
	
	printf("9. AT aes key\n\r");
	receive_index=0;
	send_ATCMD((char *) nATCpin_Set9);
	Delay(1000);

	printf("9. AT aes key\n\r");
	receive_index=0;
	send_ATCMD((char *) nATCpin_9);
	Delay(1000);
	
	printf("10. AT output power.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATCRFOP_Set10);
	Delay(1000);
	
	printf("10. AT output power.\n\r");
	receive_index=0;
	send_ATCMD((char *) nATCRFOP_10);
	Delay(1000);
	
	Button_Init();
	
	for(;;){
		printf("please press blue button.\n\r");
		while (Button_GetState() == 0);
		receive_index=0;
		send_ATCMD((char *) nATSend_2);
		Delay(1000);
	}
	
	
	
}
