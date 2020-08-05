#include<stdio.h>
#include<stdlib.h>
void at(int *);

int main(void)
{
	int a=5;
	printf("Before call at(),a=%d\n",a);
	at(&a);
	printf("After call at(),a=%d\n",a);
	

	
	system("pause");
	return 0;
}
void at(int *p)
{
	*p=*p+30;
}
