#include <stdio.h>
#include <stdlib.h>
void func(void);
int a=50;
int main(void)
{
	int a=100;
	printf("Before call fun() , a=%d\n",a);
	func();
	printf("After call fun() , a=%d\n",a);
	system("pause");
	return 0;
}

void func(void)
{
	a = a + 300;
	printf("In func() function, a=%d\n",a);
}


