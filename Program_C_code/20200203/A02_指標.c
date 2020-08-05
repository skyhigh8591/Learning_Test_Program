#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int *ptr,num=20;
	ptr=&num;
	printf("num=%d\n&num=%p\n",num,&num);
	printf("**************************************\n");
	printf("*ptr=%d\n ptr=%p\n &ptr=%p\n",*ptr,ptr,&ptr);
		
	system("pause");
	return 0;
}
