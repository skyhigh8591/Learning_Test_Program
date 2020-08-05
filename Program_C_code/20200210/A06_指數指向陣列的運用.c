#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a[4]={3,5,7,9};
	int i,sum=0;
	int *ptr;
	ptr=a;
	printf("%d\n",*ptr);
	printf("%d\n",*(ptr+1));
	printf("%d\n",*(ptr-1));
	printf("%d\n",*(ptr+2));
	system("pause");
	return 0;
}

