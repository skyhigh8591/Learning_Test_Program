#include <stdio.h>
#include <stdlib.h>
void fun(void);
int main(void)
{
	int a=100;
	printf("Before call fun() , a=%d\n",a);
	fun();
	printf("After call fun() , a=%d\n",a);
	system("pause");
	return 0;
}

void fun(void)
{
	int a=300;
	printf("In func() function, a=%d\n",a);
}


