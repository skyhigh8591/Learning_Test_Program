#include<stdlib.h>
#include<stdio.h>


int main(void)
{
	int i,j,z;
	int maze[2][4]={{30,35,26,32},{33,34,30,29}};
	
	for(i=0;i<2;i++)
	{
		printf("第%d個銷售員成績\n",i+1);
		for(j=0;j<4;j++)
		{
			printf("%3d",maze[i][j]);
			z=z+maze[i][j];
			
		}
		printf("\n第%d個銷售員總和成績為%d\n",i+1,z);
		z=0; 
		printf("\n");
	}
	
	
	///////////////////////////////////////
	system("pause");
	return 0;	
}

