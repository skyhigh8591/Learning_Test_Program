#include <stdio.h>
#include <stdlib.h>

int fac(int,int);

int main(void)
{
	printf("fac(4)= %d\n",fac(2,3));
	
	
	system("pause");
	return 0;
}


int fac(int n,int m)
{
	if(m>0)
	{
		return n*fac(n,m-1); // 4*
	}
	else
	{
		return 1;
	}
}
