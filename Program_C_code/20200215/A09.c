#include<stdio.h>
#include<stdlib.h>
#define MAX 3
int main(void)
{
	
	float total;
	struct record
	{
		int a;
		int b;
		float c;
	}num;
	struct record *ptr;
	ptr=&num;
	ptr->a=78;
	ptr->b=89;
	ptr->c=234.5;
	total=ptr->a+ptr->b+ptr->c;
	printf("Sum : %.1f\n",total);
	printf("Ave : %.1f\n",total/3.0);
	
	
	
	system("pause");
	return 0;
}
