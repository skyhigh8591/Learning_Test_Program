/**   Project name : 
*   
--------------------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 
extern void stdout_init (void);
extern void Delay(uint32_t dlyTicks);
extern volatile uint8_t key_number;
volatile static void SetSysClock(void);
volatile void SysTick_Handler (void);
volatile uint32_t Button_GetState (void);
#define NUM_KEYS  1                
#define USER    1
void GPIOA6_8_init(void)
{
	RCC->AHBENR |=0x1ul <<17;
	
	GPIOA->MODER &= ~((0x3ul<<6*2)|(0x3ul<<7*2)|(0x3ul<<8*2));
	GPIOA->MODER |= 0x1ul<<6*2|0x1ul<<7*2|0x1ul<<8*2;
	
	GPIOA->OSPEEDR &= ~((0x3ul<<6*2)|(0x3ul<<7*2)|(0x3ul<<8*2));
	GPIOA->OSPEEDR |= 0x1ul<<6*2|0x1ul<<7*2|0x1ul<<8*2;
}
void select_colorLED(uint8_t color)
{
	GPIOA->ODR &= ~ (0x7ul<<6);
	GPIOA->ODR |= color<<6;
}
void colorLed_main (void) {        // User application starts here
	GPIOA6_8_init();
	GPIOA->ODR &= ~ (0x7ul<<6);
}