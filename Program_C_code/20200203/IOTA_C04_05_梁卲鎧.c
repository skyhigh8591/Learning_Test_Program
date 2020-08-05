#include<stdio.h>
#include<stdlib.h>
void count(int *);

int main(void)
{
	int num=0;
	printf("Before call at(),a=%d\n",num);
	count(&num);
	printf(" call_1 count(),a=%d\n",num);
	count(&num);
	printf(" call_2 count(),a=%d\n",num);
	count(&num);
	printf(" call_3 count(),a=%d\n",num);
	

	
	system("pause");
	return 0;
}
void count(int *p)
{
	*p=*p+1;
}
