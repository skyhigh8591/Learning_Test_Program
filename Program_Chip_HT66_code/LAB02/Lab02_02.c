//Lab02_02    
/*   Basic C Program 
     while() and do while		*/
#include <HT66F2390.H>  
void main()						//�����u�ƥN�X
{	unsigned char i=1,j=0;
	while (i<=10)
	{	j+=i;					//j=j+i
		i++;					//i=i+1 or i+=1;
	}	
//  �Ĥ@�q
	i=j=0;
	while (i++<10)
	{	j=j+i;					//�Ĥ@�� i=? (0 ro 1)
	}	
//	�ĤG�q
	i=j=0;
	do
	{	j=j+i;
	} while (i++<10);			//55! (Post-increment)	
//	�ĤT�q	
	i=j=0;
	do
	{	j=j+i;
	} while (++i<10);			//45 Why? (Pre-increment)	)
	GCC_NOP();					//for Break Point Only
}