//Lab02_08    
/*   Basic C Program 
     Local and Global Variable */
#include <HT66F2390.H> 					
#include "MyType.h"					
void swapV(void);					
u8 i,j;					//�����ܼƕ�
void main()
{	i=20; j=50;
	swapV();						
	GCC_NOP();			//�]�_�I�[��
}
void swapV()			//�ǭȩI�s			
{ 	u8	temp;			//�楬�����[��
	temp=i;
	i=j;
	j=temp;
}
	