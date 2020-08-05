#include<stdio.h>
#include<stdlib.h>

int cub(int);
int main(void)
{
	int c;
	int z=6;
	c=cub(z);
	printf("五的第%d次方=%d\n",z,c);	
	system("pause");
	return 0;
}

int cub(int n)
{
	int z=1,i;
	for(i=1;i<=n;i++)
	{
		z=z*5;
	}
	return z;
}
