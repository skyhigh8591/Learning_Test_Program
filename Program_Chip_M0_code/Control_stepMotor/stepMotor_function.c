
#include <stdio.h>
#include  "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h" 

const uint32_t TotalSteps = 4096;

volatile uint32_t rpmDelayTime;
volatile uint32_t Tim7_tick;

volatile uint8_t phaseNumber;
volatile int currentStep;

//--------------------------
// 100us timer
//-------------------------
void Config_TIM7(void)
{
	RCC->APB1ENR |= 0x1ul << 5;
	//產生0.1ms
	TIM7->PSC = 48-1;
	TIM7->ARR = 100-1;
	TIM7->CNT = 0;
	TIM7->DIER |= 0x1ul;
	TIM7->CR1 |= 0x1ul;
	
	NVIC_SetPriority(TIM7_IRQn, 2);
	NVIC_EnableIRQ(TIM7_IRQn);
}
//------------------------
void TIM7_IRQHandler(void)
{
	Tim7_tick++;
	TIM7->SR &= ~ 0x1ul;
}
//-----------------
void motorDelay(uint32_t delay)
{
	uint32_t currentTick;
	currentTick =Tim7_tick;
	while ((Tim7_tick -currentTick) < delay){ 
		__NOP;
	}
}
//---------------------------------
void setRpm(uint32_t rpm)
{
	if ( rpm <1){
		rpmDelayTime = 146;
	}else if ( rpm > 18){
		rpmDelayTime =8 ;
	}else{
		rpmDelayTime = 600000/(TotalSteps*rpm);		
	}
	printf("rpmDelayTime = %d \n\r", rpmDelayTime);
	phaseNumber = 0;
	currentStep = 0 ;
	
}
//-----------------------
void setValue(int index)
{
	uint32_t pattern[]={0x01,0x3ul,0x2ul,0x6ul,0x4ul,0xcul,0x8ul,0x9ul,0};
	
	GPIOC->ODR &= ~ 0xful;
	GPIOC->ODR |= pattern[index];
	motorDelay(rpmDelayTime);
}
//---------------------------
void moveCW(void)  //順時針
{
	setValue(phaseNumber);
	phaseNumber++;
	
	if  (phaseNumber > 7) phaseNumber = 0;
	
	currentStep++;
	if (currentStep >= TotalSteps)
		currentStep=currentStep-TotalSteps;
}
//---------------------------
  //逆時針
void moveCCW(void)
{
	setValue(phaseNumber);
		
	if  (phaseNumber == 0) 
		phaseNumber = 7;
	else
		phaseNumber--;
	
	currentStep--;
	if (currentStep < 0)
		currentStep = currentStep+TotalSteps;
}
//--------------------------------
void stopMotor(void)
{
	phaseNumber =8;
	setValue(phaseNumber);
	currentStep= 0;
	
}
//----------------------------
void motor_moveStep(uint8_t clockwise, uint32_t numStep)
{
	for (int i=0; i<numStep;i++)
	{ 
		if (clockwise ==1) 
			moveCW();
		else 
			moveCCW();
	}
}	
//---------------------------
void motor_moveDegree(uint8_t clockwise,uint32_t degree)
{
	int nStep = ( degree * TotalSteps)/360;
	motor_moveStep(clockwise,nStep);
	
}
