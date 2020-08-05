#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num[3][4]={{1,2,3,4},{5,6,7,8},{9,10,11,12}};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("num[%d][%d]= %d,	address=%p\n",i,j,*(*(num+i)+j),*(num+i)+j);
		}
		
	}
	
	
	
	
	
	system("pause");
	return 0;
}

