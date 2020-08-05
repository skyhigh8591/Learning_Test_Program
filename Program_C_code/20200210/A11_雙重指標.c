#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int p=20;
	int *ptr1,**ptr2;
	ptr1=&p;
	ptr2=&ptr1;
	printf("p=%d, &p=%p, *ptr1=%d, ptr1=%p, &ptr1=%p\n",p,&p,*ptr1,ptr1,&ptr1);
	printf("**ptr2=%d, *ptr2=%p, ptr2=%d, \n&ptr2=%p\n",**ptr2,*ptr2,ptr2,&ptr2);
	system("pause");
	return 0;
}

