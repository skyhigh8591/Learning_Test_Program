#include<stdio.h>
#include<stdlib.h>
void swap(int *, int *);

int main(void)
{
	int a=5,b=20;
	printf("Before swap ==> ");
	printf("a=%d,b=%d\n",a,b);
	
	swap(&a,&b);
	printf("After swap ==> ");
	printf("a=%d,b=%d\n",a,b);
	
	system("pause");
	return 0;
}
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}
