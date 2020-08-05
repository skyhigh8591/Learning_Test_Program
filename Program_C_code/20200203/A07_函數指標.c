#include<stdio.h>
#include<stdlib.h>
void address(int *);

int main(void)
{
	int a=12,*ptr;
	ptr=&a;
	printf("a=%p,\n",&a);
	address(ptr);
	
	system("pause");
	return 0;
}
void address(int *p1)
{
	printf("Address: %p,Variable content: %d\n",p1,*p1);
}
