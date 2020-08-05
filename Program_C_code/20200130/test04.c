#include<stdio.h>
#include<stdlib.h>
void showChar(char,int);

int main(void)
{
	int i,n,j;
	printf("please input he layer:");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		for(j=9;j>=(9-i);j--)
		{
			
		printf("%d",j);
		
		}
	
	printf("\n");
	}
	system("pause");	
	return 0;		
}

void showChar(char ch,int n)
{
	int i;
	for(i=0;i<n;i++)
	{
		printf("%c",ch);
	}
}
