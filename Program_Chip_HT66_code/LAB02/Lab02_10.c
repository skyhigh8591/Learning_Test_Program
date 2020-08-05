//Lab02_10    
/*   Basic C Program 
     switch case Demo*/
#include <HT66F2390.H> 				     
#include "MyType.h"
#define LED_Port	_pc					//Port C Data Register
#define LED_PortC	_pcc				//Port C Control Register		
void main()
{	u8 x=0;
	_wdtc=0b10101111;
	LED_Port=0; LED_PortC=0;
	while(1)
	{	switch (x)
		{	case 1: LED_Port=~0x01;
					break;
			case 2: LED_Port=~0x02;
					break;					
			case 3: LED_Port=~0x04;
					break;
			case 4: LED_Port=~(1<<3);	//�N1�����T�줸
					break;
			case 5: LED_Port=~(1<<4);
					break;
			case 6: LED_Port=~(1<<5);
					break;
			case 7: LED_Port=~(1<<6);
					break;
			case 8: LED_Port=~(1<<7);
					break;
			default:					//x!=1~8�ɰ��楻�q
					x=0;
		}
		x+=1;
		GCC_DELAY(80000);			
	}
}	