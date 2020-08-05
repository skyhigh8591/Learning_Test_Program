#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int main(void)
{
	int i,num,flag=0;
	int B[MAX]={33,77,66,51,33,19};
	printf("the value of an array element:");
	for(i=0;i<MAX;i++)
	{
		printf(" %d",B[i]);
	}
	printf("\nPlease input an integer:");
	scanf("%d",&num);
	for(i=0;i<MAX;i++)
	{
		if(B[i]==num)
		{
			printf("found it! B[%d]= %d\n",i,B[i]);
			flag=1;
		}
	}
	if(flag==0)
	{
		printf("Not found!\n");
	}
	else
	{
		printf("found!\n");
	}
	///////////////////////////////////////
	system("pause");
	return 0;	
}

