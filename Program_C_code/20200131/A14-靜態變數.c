#include <stdio.h>
#include <stdlib.h>
void func(void);

int main(void)
{
	func();
	func();
	func();
	func();
	
	system("pause");
	return 0;
}

void func(void)
{
	static int a=200; //宣告A為靜態變數 
	printf("In func() function, a=%d\n",a);
	a = a+200;
}

