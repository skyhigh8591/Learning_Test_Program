#include<stdio.h>
#include<stdlib.h>
void sum(int , int *);

int main(void)
{
	int n,total;
	printf("Please input an integer: ");
	scanf("%d",&n);
	sum(n,&total);
	printf("1+2+.....+%d=%d\n",n,total);
	
	system("pause");
	return 0;
}
void sum(int n,int *total)
{
	int i,m=0;
	for(i=1;i<=n;i++)
	{
		m=m+i;
	}
	*total=m;
}
