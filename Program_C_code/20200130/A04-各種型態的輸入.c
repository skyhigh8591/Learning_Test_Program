#include<stdio.h>
#include<stdlib.h>
#define ROW 2
#define COL 3 

int main(void)
{
	int num1 , num2;
	double po;
	char str[20];
	printf("inout two number:\n");
	scanf("%d %d",&num1,&num2);
	printf(" ===> %d + %d = %d\n\n",num1,num2,num1+num2);
	
	printf("input a floating point:\n");
	scanf("%lf",&po);	
	printf(" ===> %f is %e \n\n",po,po);
	
	printf("input a string:\n");
	scanf("%s",&str);
	printf(" ===> %s \n\n",str);
	
	printf("input at most 10 chars:\n");
	scanf("%10s",&str);
	printf(" ===> %s \n\n",str);
	
	
	system("pause");
	return 0;		
}

