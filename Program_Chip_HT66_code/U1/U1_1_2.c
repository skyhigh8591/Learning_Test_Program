// PROGRAM	: U1_1_2.c								2017.0413
// FUNCTION	: LED Scanning Demo Program (Built-in)	By Steven
#include <HT66F2390.h>
#include "MyType.h"			
#define LED_Port  _pc								
#define LED_PortC _pcc
void Delayms(u16);									//�禡�쫬�ŧi						
void main()
{	_wdtc=0b10101111;								//�����ݭ̪��p�ɾ�
	LED_PortC=0x0;									//�]�w LED_Port ����X�Ҧ�
	LED_Port=0xFE;									//�]�w LED_Port ���
	while(1)
	{	while(LED_Port & 0b10000000)				//�YMSB����0�h�j���~��
		{	Delayms(100);
			GCC_RL(LED_Port);						//����
		}
		while(LED_Port & 0b00000001)				//�YLSB����0�h�j���~��	
		{	Delayms(200);
			GCC_RR(LED_Port);						//�k��
		}				
	}
}
void Delayms(u16 del)								//����del*200���O�g��
{	u16 i;											//@fSYS=8MH,����del*1ms
	for(i=0;i<del;i++) GCC_DELAY(2000);
}	