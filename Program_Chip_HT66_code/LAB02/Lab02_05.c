//Lab02_05    
/*   Basic C Program 
     Type Define example	*/
#include <HT66F2390.H> 
#include "MyType.h"			//�sĶ���ܷ�e�u�@�ؿ���A�䤣��A�����ҳ]�w�ѼƧ�					
//#include <MyType.h>		//�sĶ���u�����ҳ]�w�ѼƧ�(Can not Find)					
void main()
{	u8 i=0,j=0;
	while(1)
	{	if(i<=10)
		{	j+=i;				
			i++;
		}	
		else 
		{	break;		
		}
	}
	GCC_NOP();				//for Break Point Only		
}