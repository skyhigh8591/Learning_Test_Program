/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern void Delay(uint32_t dlyTicks);
extern volatile uint8_t key_number;

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Key_1 1
#define Key_2 2
#define Key_3 3
#define Key_4 4

//-----------------------------
#define AllLed_on   1
#define AllLed_off  2
#define OddLed_on   3
#define EvenLed_on  4 
#define BitLed_on   5

//---------------------------
void GPIOC0_7_init(void) {
	
	RCC->AHBENR |= 0x1ul << 19;
	
	GPIOC->MODER &= ~(0xfffful);
	GPIOC->MODER |= 0x5555ul;
	
	GPIOC->OSPEEDR &= ~ 0xfffful;
	GPIOC->OSPEEDR |= ~ 0x5555ul;
}	


void LedChange(uint8_t mode) {
    uint32_t bitValue, currentValue;
	switch (mode) {
		case AllLed_on:
			GPIOC->ODR |= 0xfful;
			break;
		case AllLed_off:
			GPIOC->ODR &= ~0xfful;
//		    GPIOC->ODR &= ~0xffffff00ul;
			break;
		case OddLed_on:
			GPIOC->ODR &= ~0xfful;
			GPIOC->ODR |= 0xaaul;
			break;
		case EvenLed_on:
			GPIOC->ODR &= ~0xfful;
			GPIOC->ODR |= 0x55ul;
			break;
		case BitLed_on:
			GPIOC->ODR &= ~0xfful;
		    currentValue = 1;
		    for(int i=0;i<8;i++) {
				bitValue = 0x1ul;
				bitValue <<= i;
				GPIOC->ODR &= ~currentValue;
				GPIOC->ODR |= bitValue;
				currentValue = bitValue;
				if (key_number != Key_4) break;
				Delay(500);
			}	
			break;
	}	
}	



/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void led_main (void) {        // User application starts here
	
	GPIOC0_7_init();	

}
