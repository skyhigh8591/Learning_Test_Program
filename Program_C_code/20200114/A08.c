#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int num;
	printf("Please input an integer: ");
	scanf("%d",&num);
	if(num>=0)
	{		
		if(num<=20)
		{	
		printf("number between 0-20\n");
		}
	}
	else
	{
	printf("number less than 0\n");
	}
	system("pause");
	return 0;
	
}	
