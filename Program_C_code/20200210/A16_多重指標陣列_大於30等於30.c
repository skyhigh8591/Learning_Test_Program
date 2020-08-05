#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int num[3][4]={{12,23,35,48},{25,16,17,18},{39,10,21,52}};
	int i,j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<4;j++)
		{
			if(*(*(num+i)+j)>30)
			{
				*(*(num+i)+j)=30;
			}
			printf("%3d",*(*(num+i)+j));
		}	
	}
	
	
	
	
	system("pause");
	return 0;
}

