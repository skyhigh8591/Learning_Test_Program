#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	
	
	
	int i,sum=0;
	for(i=1;i<=100;i)
	{
		sum += i;
		printf("i = %d\n",i);
		printf("sum = %d\n",sum);
		i = i + 2;
		
		
	}
	
	
	system("pause");
	return 0; 
}
