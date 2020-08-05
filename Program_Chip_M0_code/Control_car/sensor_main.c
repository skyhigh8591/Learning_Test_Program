/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

volatile uint32_t ADCValue[5];

extern void Car_direction(uint8_t dir_cmd);
extern void PWMValue_ch4_right(uint32_t value);
extern void PWMValue_ch3_left(uint32_t value);
extern void  Delay(uint32_t dlyTicks);
extern volatile uint8_t ADCFlag;
#define CarDir_stop			0
#define CarDir_forward	1
#define CarDir_right		2
#define CarDir_left			3
#define CarDir_backward	4



//---------------------------------
void Config_PC123(void)
{
	RCC->AHBENR |= 0x1ul << 19 ;
	GPIOC->MODER |= 0xfful;
	
}

//----------------------------------
void Config_PB1(void)
{
	RCC->AHBENR |= 0x1ul << 18;
	GPIOB->MODER |= 0x3ul << 1*2;
}

//-----------------------------
void Config_ADC(void)
{
	RCC->APB2ENR |= 0x1ul << 9;
	
	RCC->CR2|=0x1ul;
	while((RCC->CR2 & ( 0x1ul<<1) ) == 0);
	
	ADC1->CR |= 0x1ul << 31;
	while(  (ADC1->CR & (0x1ul<<31) ) == (0x1ul << 31) );
	
	ADC1->CFGR2 &= ~ (0x3ul << 30);
	ADC1->CFGR1 &= ~ (0x1ul<<13);
	ADC1->CFGR1 &= ~ (0x3ul << 3);
	ADC1->CFGR1 |= 0x1ul << 3;
	
	ADC1->CHSELR |= 0xful << 10 | 0x1ul << 9 ;
	ADC1->SMPR &= ~ (0x7ul);
	ADC1->SMPR |= 0x4ul;
	
	ADC1->CR |= 0x1ul;
	while( (ADC1->ISR & 0x1ul)==0); 
		
}

void Config_timer7(void)
{
	RCC->APB1ENR |= 0x1ul << 5;
	
	TIM7->PSC = 4800-1;
	TIM7->ARR = 1000-1;
	TIM7->CNT = 0;
	
	TIM7->CR1 |= 0x1ul << 7 | 0x1ul;
	TIM7->DIER |= 0x1ul;
	
	NVIC_SetPriority(TIM7_IRQn,2);
	NVIC_EnableIRQ(TIM7_IRQn);
}
//-----------------------

void TIM7_IRQHandler(void)
{
	
	TIM7->SR &= ~ 0x1ul;
	
}
/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void senson_main (void) {        // User application starts here
	
	
	Config_PB1();
	Config_PC123();
	Config_ADC();
	Config_timer7();
	
		for(;;)
	{
		ADC1->CR |= 0x1u << 2 ;
		for(int i = 0 ; i < 5; i++){
		while((ADC1->ISR & (0x1ul<<2) ) == 0);
			ADCValue[i]= ADC1->DR;
		}
	
			if(ADCValue[0]>650){
			printf("PB.1 and value = %d \n\r",ADCValue[0]);
				PWMValue_ch3_left(70);
				PWMValue_ch4_right(70);
				Car_direction(CarDir_backward);
				Delay(100);
				Car_direction(CarDir_stop);
		}
			
		if(ADCFlag){
					if(ADCValue[1]<700||ADCValue[2]<700){
						printf("PC.0 and value = %d \n\r",ADCValue[1]);
						printf("PC.1 and value = %d \n\r",ADCValue[2]);
						PWMValue_ch3_left(70);
						PWMValue_ch4_right(70);
						Car_direction(CarDir_backward);
						Delay(200);
						Car_direction(CarDir_stop);
					}
		
					if(ADCValue[3]<700||ADCValue[4]<700){
						printf("PC.2 and value = %d \n\r",ADCValue[3]);
						printf("PC.3 and value = %d \n\r",ADCValue[4]);
						PWMValue_ch3_left(70);
						PWMValue_ch4_right(70);
						Car_direction(CarDir_forward);
						Delay(200);
						Car_direction(CarDir_stop);
					}
				}
		
		
		Delay(3000);
		
	}
	
	
}