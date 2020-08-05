#include<stdio.h>
#include<stdlib.h>
int add(int,int);
int add(int num1,int num2)
{
	int a;
	a=num1+num2;
	return a;
}

int main(void)
{
	int sum=0 ,a=5 ,b=6;
	sum = add(a,b);
	printf("%d+%d=%d\n",a,b,sum);
		
	system("pause");
	return 0;		
}


