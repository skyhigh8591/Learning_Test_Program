#include<stdio.h>
#include<stdlib.h>
void rect(int, int, int *, int *);

int main(void)
{
	int a=5, b=8;
	int area, peri;
	
	rect(a,b,&area,&peri);
	printf("area=%d, total length=%d\n",area,peri);
	
	system("pause");
	return 0;
}
void rect(int a, int b, int *area, int *peri)
{
	*area=a*b;
	*peri=2*(a+b);
}
