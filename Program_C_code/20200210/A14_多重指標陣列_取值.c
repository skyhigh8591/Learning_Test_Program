#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int i;
	for(i=0;i<3;i++)
	{
		printf("**(num+%d)=%d\n",i,**(num+i));
	}
	
	
	
	
	
	system("pause");
	return 0;
}

