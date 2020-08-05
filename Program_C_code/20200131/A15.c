#include <stdio.h>
#include <stdlib.h>
void add20(int,int);
int main(void)
{
	int a=5, b=9;
	printf("Before call add20() function: ");
	printf("a=%d, b=%d\n",a,b);
	add20(a,b);
	printf("After call add20() function: ");
	printf("a=%d, b=%d\n",a,b);
	system("pause");
	return 0;
}

void add20(int a,int b)
{
	a=a+20;
	b=b+20;
}

