//Lab02_1    
/*   Basic C Program 
     for() 					*/
#include <HT66F2390.H>  
void main()					//取消優化代碼
{	int i;
	int sum=0;	//
	for(i=0;i<=100;i++)
	{	sum=sum+i;				//sum+=i;
	}
	GCC_NOP();				//for Break Point Only
}
