#include<stdlib.h>
#include<stdio.h>
#define SQUARE(x) (x)*(x)

int main(void)
{
	int n,i=1,sum=0;
	do
	{
		printf("Please input the value of n(n>0):");
		scanf("%d",&n);
		fflush(stdin);
	}while(n<=0);
	do
	{
		sum=sum+i;
		i=i+1;
	}while(i<=n);
	printf("1+2+3...+%d=%d",n,sum);
	///////////////////////////////////////
	system("pause");
	return 0;
	
	
	
	
	
	
	
}

