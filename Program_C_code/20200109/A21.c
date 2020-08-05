#include<stdlib.h>
#include<stdio.h>
int main(void)
{
	int i,sum=0;
	for(i=0;i<=5;i++)
	{
		
		printf("sum = %d\n",sum);
		printf("i = %d\n",i);
		printf("sum = %d + %d \n",i,sum);
		sum = sum + i;
		printf("sum = %d\n",sum);
		system("pause");
	}
	system("pause");
	return 0; 
}
