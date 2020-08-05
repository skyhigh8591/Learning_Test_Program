#include<stdio.h>
#include<stdlib.h>
void sum(int),fac(int);

int main(void)
{
	fac(4);
	sum(4);
	
	
	
		
	system("pause");
	return 0;		
}

void fac(int a)
{
	int i,total=1;
	
	for(i=1;i<=a;i++)
	{
		total = total*i;
	}
	printf("1x2x3....x%d=%d\n",a,total);
}

void sum(int b)
{
	int c,total=0;
	for(c=1;c<=b;c++)
	{
		total= total+c;
	}
	printf("1+2+3....+%d=%d\n",b,total);
}
