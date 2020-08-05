#include<stdio.h>
#include<stdlib.h>
void kitty(int);

int main(void)
{
	
	int n;
	printf("¿é¤J¦æ¼Æ");
	scanf("%d",&n);
	kitty(n);	
	system("pause");
	return 0;		
}

void kitty(int k)
{
	int  i;
	for( i = 1 ; i <= k ; i++)
	{
	printf("%d Hello Kitty\n",i);	
	}
}
