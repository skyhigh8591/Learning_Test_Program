#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	struct data
	{
		int num;
		char ch;
		double dist;
	}abc;
	
	printf("abc.num = %d,	abc.ch = %d,	abc.dist = %d\n",sizeof(abc.num),sizeof(abc.ch),sizeof(abc.dist));

	

	system("pause");
	return 0;
}
