#include<stdio.h>
#include<stdlib.h>
void fac(int);
int main(void)
{
	
	
	fac(5);
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
