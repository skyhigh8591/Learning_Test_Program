#include<stdio.h>
#include<stdlib.h>
void *max(int *, int *);

int main(void)
{
	int a=12, b=17, *ptr;
	ptr=max(&a,&b);
	printf("max=%d\n",*ptr);
	
	system("pause");
	return 0;
}
void *max(int *a, int *b)
{
	if(*a>*b)
	{
		return a;
	}
	else
	{
		return b;
	}
}
