//Lab02_06    
/*   Basic C Program 
     Function example	*/		//�����u�ƥN�X
#include <HT66F2390.H> 
#include "MyType.h"				//�sĶ���ܷ�e�u�@�ؿ���A�䤣��A�����ҳ]�w�ѼƧ�					
u8 FindMax(u8,u8);				//��ƭ쫬�ŧi Function Prototype
void main()
{	u8 i=20,j=50,max;
	max=FindMax(i,j);			//�ǭȩI�s (Call By Value)
	GCC_NOP();					//for Break Point Only	
}
u8 FindMax(u8 i, u8 j)			//��Ʃw�q Function Definition, Local Variable
{ 	u8 temp;
    if(i>j) temp=i ; else temp=j;
    //temp = (i>j) ? i : j;		//�T�B�⤸���O
    i+=10; j+=10;				//Local Variable Test Only	
    return	temp;
}

	