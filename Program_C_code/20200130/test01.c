#include<stdio.h>
#include<stdlib.h>
void  s1 (int);

int main(void)
{
	int i;
	printf("Input an integer:");
	scanf("%d",&i);
    s1(i);	
	system("pause");
	return 0;		
}

void s1 (int n)
{
	if(n%2==0)
	{
		printf("°¸¼Æ\n");
	}
	else
	{
		printf("©_¼Æ\n");
	}
}
