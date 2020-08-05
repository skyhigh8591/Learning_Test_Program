/**   Project name : 
*�ާ@�q�e������ 1~4�A��ܼ��񭵼֡BLED�ʧ@   
--------------------------------------------------------------------------------------*/

#include <stdio.h>

#include "stm32f0xx.h"          // File name depends on device used
#include "RTE_Components.h"      // Component selection 

extern void stdout_init (void);
extern volatile uint8_t key_number;
extern void LedChange(uint8_t mode);
extern void key_main (void);

//volatile uint32_t msTicks;         // Counter for millisecond Interval
volatile uint32_t Tim2_Ticks;
volatile uint8_t melody_number;

#define NUM_KEYS  1                     /* Number of available keys           */

/* Keys for NUCLEO Board */
#define USER    1

#define Key_0 0
#define Key_1 1
#define Key_2 2
#define Key_3 3
#define Key_4 4
#define Key_default 10

#define AllLed_on  1
#define AllLed_off 2
#define OddLed_on  3 
#define EvenLed_on 4
#define BitLed_on  5

//-------------------------------
void Config_Timer2(void)             //���_�έp�� for TIM2Delay     
{
	RCC-> APB1ENR |= 0x1ul ;         //enable TIM2 clk
	
	TIM2 ->PSC = 47;   //48 -1
	TIM2 ->ARR = 1000-1;
	TIM2 ->CNT = 0;
	TIM2 ->CR1 |= 0x1ul << 7  |  0x1ul ;
	TIM2 ->DIER |= 0x1ul ;
	
	NVIC_SetPriority(TIM2_IRQn,3);
	NVIC_EnableIRQ(TIM2_IRQn);
	
	//DIER �� 0bit�OUIE �����}�~�ಣ�ͤ��_ �O���_�ӦA SR�Ȧs��   SR�Ȧs���� 0BIT �@�w�n�O�o���M��
}


//-------------------------------------
void TIM2_IRQHandler (void)
{
	Tim2_Ticks++;
	TIM2 ->SR &= ~0x1ul;            //�M��SR �Ȧs��
}

//-------------------------------------
void TIM2Delay (uint32_t counter)
{
	uint32_t currentTicks;
	
	currentTicks = Tim2_Ticks;
	while((Tim2_Ticks - currentTicks) < counter)
	{
		__NOP;
	}
}	


//-----------------------------------------------
void PWMPA4_init(void)               //  
{
	RCC->AHBENR |= 0x1ul << 17 ;
	GPIOA->AFR[0] &=~( 0xful << 4*4 );
	GPIOA->AFR[0] |= 0x4ul << 4*4 ;   //�]�w�� �|���}
	
	GPIOA ->MODER &= ~(0x3ul << 4*2 );
	GPIOA ->MODER |= 0x2ul << 4*2 ;    //�]�w����L�Ҧ�	
}

//-------------------------------------------
void Config_timer14(void)            //�W�v�B���q
{
	RCC->APB1ENR |= 0x1ul << 8 ;
	TIM14->PSC = 480 -1 ;         //�Q�n�]�w���Ʀr ���n-1   �W�v
	TIM14->ARR = 261 -1 ;         //CCR1 ����W�L ARR 
	TIM14->CCR1 = 255;            //����q�j�p
	TIM14->CNT =0 ;
	TIM14->CCMR1 |= 0x6ul << 4 ;
	TIM14->CR1 |= 0x1ul << 7 ;
}

//-------------------------------------------------
void PWMPA4_enable(void)
{
	TIM14->CNT = 0;
	TIM14->CR1 |=0x1ul;
	TIM14->CCER |= 0x1ul;
}

//-------------------------------------------------
void PWMPA4_disable(void)
{
	TIM14->CCER &=  ~0x1ul;
	TIM14->CR1  &=  ~0x1ul;
}

//---------------------------------------------------
void SelectTone(uint32_t tone_number)
{
	uint32_t ToneArr[]={1,764,681,607,573,510,454,405,   
						  382,340,303,286,255,227,202,
						  191,170,152,143,128,114,101};     
	uint32_t ARRValue;	

	ARRValue=ToneArr[tone_number];      //ARR value = 0.1M/130.8 = 764.5 
	TIM14->ARR = ARRValue;              //ARR ���i��0 �|�����D
	TIM14->CNT = 0;
	TIM14->CCR1 = ARRValue *0.99 ;      //0.99 �� 0.8 �n���p
}

#define soundStop 150
#define Song_off 0
#define Song_1   1
#define Song_2   2
#define Song_3   3
#define Song_4   4
#define Song_5   5

void PlayMelody(uint8_t song_number)  //�`��  �@�絥��500ms	
{
	uint8_t note_basic[]={1,2,3,4,5,6,7,1+7,2+7,3+7,4+7,5+7,6+7,7+7,1+14,2+14,3+14,4+14,5+14,6+14,7+14};
	uint32_t tone,beat;

	uint8_t note_happy_song[]={5,5,6,5,1+7,7,5,5,6,5,2+7,1+7,5,5,5+7,3+7,1+7,7,6,4+7,4+7,3+7,1+7,2+7,1+7 };	
	uint16_t beat_happy_song[]={250,250,500,500,500,1000,250,250,500,500,500,1000,250,250,500,500,500,500,1500,
								250,250,500,500,500,1500};
	// Little Star Song	
	uint8_t note_little_star[]={1,1,5,5,6,6,5,4,4,3,3,2,2,1,5,5,4,4,3,3,2,5,5,4,4,3,3,2,1,1,5,5,6,6,5,4,4,3,3,2,2,1};
	uint16_t beat_little_star[]={500,500,500,500,500,500,1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,
								1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,1000,500,500,500,500,500,500,1000};
	//Little Bee Song	
	uint8_t  note_little_bee[]={5,3,3,4,2,2,1,2,3,4,5,5,5,5,3,3,4,2,2,1,3,5,5,3,2,2,2,2,2,3,4,3,3,3,3,3,4,5,5,3,3,4,2,2,1,3,5,5,1};			
	uint16_t beat_little_bee[]={250,250,500,250,250,500,250,250,250,250,250,250,500,250,250,500,250,250,500,250,250,250,250,1000,
								250,250,250,250,250,250,500,250,250,250,250,250,250,500,250,250,500,250,250,500,250,250,250,250,1000};	
	//Ode To Joy	
	uint8_t  note_ode_to_joy[]=
								{3+7,3+7,4+7,5+7,    5+7,4+7,3+7,2+7,  1+7,1+7,2+7,3+7,    3+7,2+7,2+7,    3+7,3+7,4+7,5+7,
								5+7,4+7,3+7,2+7,   1+7,1+7,2+7,3+7,  2+7,1+7,1+7,     2+7,2+7,3+7,1+7,    2+7,3+7,4+7,3+7,1+7,
								2+7,3+7,4+7,3+7,2+7,   1+7,2+7,5,    3+7,3+7,4+7,5+7,  5+7,4+7,3+7,2+7,  1+7,1+7,2+7,3+7,
								2+7,1+7,1+7};
	uint16_t beat_ode_to_joy[]=
								{500,500,500,500,    500,500,500,500,   500,500,500,500, 750,250,1000,  500,500,500,500,
								500,500,500,500,   500,500,500,500,  750,250,1000,  500,500,500,500,  500,250,250,500,500,
								500,250,250,500,500,   500,500,1000, 500,500,500,500,  500,500,500,500,  500,500,500,500,
								750,250,1000};
		PWMPA4_enable();
		switch(song_number)
		{
			case Song_1:
				for(int i=0 ; i<sizeof(note_basic);i++)
					{
						tone = note_basic[i];
						SelectTone(tone);
						TIM2Delay(500);
						PWMPA4_disable();
						TIM2Delay(soundStop);
						if (melody_number != Song_1)
							break;
						PWMPA4_enable();
					}
				break;
			case Song_2:
				for(int i=0 ; i<sizeof(note_happy_song);i++)
					{
						tone = note_happy_song[i];
						tone +=7;   //���հ��K��
						SelectTone(tone);
						beat = beat_happy_song[i];
						beat -= 50 ;   //�`��[�t
						TIM2Delay(beat);
						
						PWMPA4_disable();
						TIM2Delay(soundStop);
						if (melody_number != Song_2)
							break;
						PWMPA4_enable();								
					}		
				break;	
			case Song_3:
				for(int i=0 ; i<sizeof(note_little_star);i++)
					{
						tone = note_little_star[i];
						tone +=7;   //���հ��K��
						SelectTone(tone);
						beat = beat_little_star[i];
						beat -= 50 ;   //�`��[�t
						TIM2Delay(beat);						
						PWMPA4_disable();
						TIM2Delay(soundStop);
						if (melody_number != Song_3)
							break;						
						PWMPA4_enable();				
					}
				break;	
			case Song_4:
				for(int i=0 ; i<sizeof(note_little_bee);i++)
					{
						tone = note_little_bee[i];	
						tone +=7;   //���հ��K��						
						SelectTone(tone);
						beat = beat_little_bee[i];
						beat -= 100 ;   //�`��[�t
						TIM2Delay(beat);						
						PWMPA4_disable();
						TIM2Delay(soundStop);
						if (melody_number != Song_4)
							break;
						PWMPA4_enable();				
					}
				break;
			case Song_5:	
				for(int i=0 ; i<sizeof(note_ode_to_joy);i++)
					{
						tone = note_ode_to_joy[i];	
						tone +=7;   //���հ��K��						
						SelectTone(tone);
						beat = beat_ode_to_joy[i];
						beat -= 100 ;   //�`��[�t
						TIM2Delay(beat);						
						PWMPA4_disable();
						TIM2Delay(soundStop);
						if (melody_number != Song_5)
							break;
						PWMPA4_enable();				
					}
				break;						
		}
		PWMPA4_disable();
}

/*--------------------------------------------------------------------------------*/
// The processor clock is initialized by CMSIS startup + system file
/*--------------------------------------------------------------------------------*/
void melody_main (void) {        // User application starts here
	
	Config_Timer2();
	PWMPA4_init();
	Config_timer14();
	//key_main();
	melody_number=Song_off;
}