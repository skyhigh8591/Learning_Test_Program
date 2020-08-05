#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	int a[4]={3,5,7,9};
	int i,sum=0;
	int *ptr;
	ptr=a;
	for(i=0;i<4;i++)
	{
		sum+=*(ptr++);
	}
	printf("sum=%d\n",sum);
	system("pause");
	return 0;
}

