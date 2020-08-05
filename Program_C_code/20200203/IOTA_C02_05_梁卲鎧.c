#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	float *ptr,num=12.6f;
	ptr=&num;
	printf("num=%f\n&num=%p\n",num,&num);
	printf("**************************************\n");
	printf("*ptr=%f\n ptr=%p\n &ptr=%p\n",*ptr,ptr,&ptr);
		
	system("pause");
	return 0;
}
