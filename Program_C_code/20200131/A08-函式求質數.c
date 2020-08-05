#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int prime(int);
int main(void)
{
	int i;
	for(i=2;i<=80;i++)
	{
		if(prime(i)==1)
		{
			printf("%d  ",i);
		}
	}
	printf("\n");
	
	system("pause");
	return 0;
}

int prime(int num)
{
	int i;
	for(i=2;i<num;i++)
	{
		if(num%i==0)
		{
			return 0;
		}
	}
	return 1;
}
