/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);



#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define CarDir_stop			0
#define CarDir_forward	1
#define CarDir_right		2
#define CarDir_left			3
#define CarDir_backward	4



void Config_PC4567(void)
{
	RCC->AHBENR  |=    0x1ul  << 19  ;
	
	GPIOC->MODER &= ~ (0xfful << 4*2);
	GPIOC->MODER |=    0x55ul << 4*2 ;
	
	GPIOC->OSPEEDR &= ~ (0xfful << 4*2);
	GPIOC->OSPEEDR |=    0x55ul << 4*2 ;
}

//----------------------------------------------
void Config_PA0(void)
{
	RCC->AHBENR |= 0x1ul << 17;
	
	GPIOA->MODER &= ~ 0x3ul;
	GPIOA->MODER |= 0x1ul;
	
	GPIOA->OSPEEDR &= ~ 0x3ul;
	GPIOA->OSPEEDR |= 0x1ul;
	
	GPIOA->ODR |= 0x1ul;
	
}

//--------------------------------------------------
void Enable_standbyMode(void)
{
	GPIOA->ODR &=~ 0x1ul;
	
}

//--------------------------------------------
void Disable_standbyMode(void)
{
	GPIOA->ODR |= 0x1ul;
}
//--------------------------------------------
void Config_PC89(void)
{
	RCC->AHBENR |= 0x1ul << 19;
	
	GPIOC->AFR[1] &= ~ (0xful | 0xful <<4);
	
	GPIOC->MODER &= ~(0x3ul << 8*2 | 0x3ul << 9*2);
	GPIOC->MODER |= 0x1ul << 8*2 | 0x1ul << 9*2;
	
	RCC->APB1ENR |= 0x2ul;
	
	TIM3->PSC = 480-1;
	TIM3->ARR = 100-1;
	
	TIM3->CCR3= 100;
	TIM3->CCR4= 100;
	TIM3->CNT = 0;
	
	TIM3->CCMR2 |= 0x6ul << 4 | 0x6ul << 12;
	
}

//--------------------------------------------------------
void EnablePWM_ch3_left(void)
{
	
	TIM3->CNT = 0;
	TIM3->CR1 |= 0x1ul;
	TIM3->CCER |= 0x1ul << 8;
	
}

void DisablePWM_ch3_left(void)
{
	
	TIM3->CNT = 0;
	TIM3->CR1 &= ~ 0x1ul;
	TIM3->CCER &= ~ (0x1ul << 8);
	
}


void PWMValue_ch3_left(uint32_t value)
{
	TIM3->CCR3 = value;
}

//-------------------------------------
void EnablePWM_ch4_right(void)
{
	TIM3->CNT = 0;
	TIM3->CR1 &= ~ 0x1ul;
	TIM3->CCER &= ~ (0x1ul << 12);
}


void DisablePWM_ch4_right(void)
{
	
	TIM3->CNT = 0;
	TIM3->CR1 &= ~ 0x1ul;
	TIM3->CCER &= ~ (0x1ul << 12);
	
}
//-------------------------

void PWMValue_ch4_right(uint32_t value)
{
	TIM3->CCR3 = value;
}
//-----------------------------------------------
void Car_direction(uint8_t dir_cmd)
{
	switch(dir_cmd){
		case CarDir_stop:
			GPIOC->ODR |= 0xful << 4;
		break;
		case CarDir_forward:
			GPIOC->ODR &= ~ (0xful<<4);
			GPIOC->ODR |= 0x2ul << 4 | 0x2ul << 6;
		break;
		case CarDir_backward:
			GPIOC->ODR &= ~ (0xful<<4);
			GPIOC->ODR |= 0x1ul << 4 | 0x1ul << 6;
		break;
		case CarDir_right:
			GPIOC->ODR &= ~ (0xful<<4);
			GPIOC->ODR |= 0x2ul << 4 | 0x1ul << 6;
		break;
		case CarDir_left:
			GPIOC->ODR &= ~ (0xful<<4);
			GPIOC->ODR |= 0x2ul << 6 | 0x1ul << 4;
		break;
	}
}


/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void car_main (void) {        // User application starts here

	
	Config_PC4567();
	Config_PC89();
	Config_PA0();
	EnablePWM_ch3_left();
	EnablePWM_ch4_right();
//	
//	PWMValue_ch3_left(100);
//	PWMValue_ch4_left(100);
//	Car_direction(CarDir_forward);
//	Delay(5000);
//	
//	PWMValue_ch3_left(70);
//	PWMValue_ch3_left(70);
//	Car_direction(CarDir_backward);
//	Delay(5000);
//	
//	
//	//Car_direction(CarDir_right);
//	PWMValue_ch3_left(70);
//	PWMValue_ch3_left(40);
//	Car_direction(CarDir_forward);
//	Delay(5000);
//	
//	//Car_direction(CarDir_left);
//	PWMValue_ch3_left(40);
//	PWMValue_ch3_left(70);
//	Car_direction(CarDir_forward);
//	Delay(5000);
//	
//	Car_direction(CarDir_stop);
//	
//	
//	for(;;)
//	{
//		
//		
//	}
	
}