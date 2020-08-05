#include<stdlib.h>
#include<stdio.h>


int main(void)
{
	int i,j;
	int sale[2][4];
	int sum=0;
	for(i=0;j<2;i++)
	{
		for(j=0;j<4;j++)
		{
			printf("Sales%d %d quarter results: ",i+1,j+1);
			scanf("%d",&sale[i][j]);
		}
	}
	printf("\n***************************************************\n");
	for(i=0;i<2;i++)
	{
		printf("\nSales%d quarter results: ",i+1);
		for(j=0;j<4;j++)
		{
			printf("%d",sale[i][j]);
			sum = sum + sale[i][j];
		}
	}
	printf("\n2019 results for the total sales volume of %d cars\n",sum);
	///////////////////////////////////////
	system("pause");
	return 0;	
}

