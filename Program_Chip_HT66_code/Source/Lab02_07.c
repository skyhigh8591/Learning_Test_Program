//Lab02_07    
/*   Basic C Program 
     Function call By Vaule/Reference example*/
#include <HT66F2390.H>   
#include "MyType.h"					
void swapV(u8,u8);					
void swapR(u8* ,u8*);				//���� Pointer
void main()
{	u8 i=20,j=50;
	swapV(i,j);						//�ǭȩI�s
	GCC_NOP();						//�]�_�I�[��
	swapR(&i,&j);					//�ǧ}�I�s
	GCC_NOP();						//& ���}�B��l
}
void swapR(u8 *i,  u8 *j)			//Call By Reference
{ 	u8	temp;
	temp=*i;						//* ���ȹB��l
	*i=*j;
	*j=temp;
}
void swapV(u8 i, u8 j)				//Call By Value
{ 	u8	temp;
	temp=i;
	i=j;
	j=temp;
	GCC_NOP();						//�]�_�I�[��	
}
	