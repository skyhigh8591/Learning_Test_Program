/**   Project name : 
*   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void Delay(uint32_t dlyTicks);
extern volatile uint32_t msTicks;         // Counter for millisecond Interval

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

char tempString[6];
char humdString[6];

 
//------------------------
void Config_PA12(void){
	RCC->AHBENR |= 0x1ul << 17;
	GPIOA->MODER &= ~(0x3ul << 12*2);
	GPIOA->MODER |= 0x1ul << 12*2;
	
	GPIOA->OSPEEDR &= ~(0x3ul << 12*2);
	GPIOA->OSPEEDR |= 0x1ul << 12*2;
}
//-----
void Set_high(void){
	GPIOA->ODR |= 0x1ul << 12;
}
//------
void Set_low(void){
	GPIOA->ODR &= ~(0x1ul << 12);
}
//-------------------------------------------
void Set_output(void){
	GPIOA->MODER |= 0x1ul << 12*2;     //PA12: MCU 先輸出，sensor 再輸入
}
//---------------------------------------
void Set_input(void){
	GPIOA->MODER &= ~ (0x3ul << 12*2);
}

//-----------------------------------------
void Get_TempHumd(void){
	uint32_t startTicks, pulseWidth;
	uint32_t data[43];
	uint32_t dataValue, humData, tempData, parityData ;
	uint32_t calData, calParity; 
	uint32_t tempValue, humdValue;
	float tempReal,humdReal;
	

		
		Set_output();        //腳位
		Set_high();          //start signal 是 high
		Delay(5);            //5ms
		startTicks =msTicks;
		Set_low();      
		Delay(5);            //5ms
		Set_high();
		
		Set_input();
		for (int i = 0; i < 42; i++){
			pulseWidth = 0;
			while ( (GPIOA->IDR & (0x1ul << 12)) == 0){
				pulseWidth++;
				if (msTicks-startTicks > 500)     //大於 500ms 即異常跳出     
					break;
			}
			while ((GPIOA->IDR & (0x1ul << 12)) == (0x1ul << 12)){
				pulseWidth++;
				if (msTicks-startTicks > 500)     //大於 500ms 即異常跳出     
					break;
			}
			data[i] = pulseWidth;
		}
		
//		for (int i = 0; i < 42; i++){
//			printf("data value %d = %d \n\r",i , data[i]);  //i=2之後才有意義
//		}
		
		dataValue = 0;
		parityData = 0;
		for (int i = 2; i < 42; i++){
			if (i < 34){
				if (data[i] > 190)                 //代表"1"
					dataValue |= 0x1ul;            //set "1"
				if (i < 33)
					dataValue = dataValue << 1;
			} else{
				if (data[i] > 190)
					parityData |= 0x1ul;
				if (i < 41)
					parityData = parityData << 1;			
			}
		}
//		printf("data value =%x. \n\r", dataValue);  
//		printf("parity value =%x. \n\r", parityData);
		//----------------------------
		calData = dataValue;
		calParity = 0;
		for (int i = 0; i < 4; i++){                   //4-byte (high-humidity、low-humidity、high temperature、low temperatur)
			calParity = calParity + (calData & 0xff);  //parity checksum
			calData = calData >> 8;
		}
//		printf("parity checksum = %x. \n\r",calParity);
		
		if ((calParity & 0xfful) == parityData){       // calParity & 0xfful 是為了避免進位
			tempValue = dataValue & 0xfffful;
			humdValue = (dataValue >> 16) & 0xfffful;
			tempReal = tempValue / 10.0;
//			printf("temp value =%f. \n\r", tempReal);
		    humdReal = humdValue / 10.0;
//			printf("humd value =%f. \n\r", humdReal);
			
			sprintf(tempString, "%0.2f", tempReal);
			sprintf(humdString, "%0.2f", humdReal);

			printf("temp string =%s \n\r", tempString);
			printf("humd string =%s \n\r", humdString);			
			
		} else {
			printf("parity check error. \n\r");
		}
}
/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void temp_main (void) {        // User application starts here
	

	Config_PA12();

	

}