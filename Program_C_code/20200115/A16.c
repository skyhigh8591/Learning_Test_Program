#include<stdlib.h>
#include<stdio.h>
#define LEN 9

int main(void)
{
	int B[2][4][3]={{{21,32,65},
					{78,95,76},
					{79,44,65},
					{89,54,73}},
					{{32,56,89},
					{43,23,32},
					{32,56,78},
					{94,78,45}}};
	int i,j,k,max=B[0][0][0];
	
	for(i=0;i<2;i++)
	{
		for(j=0;j<4;j++)
		{
			for(k=0;k<3;k++)
			{
				if(max<B[i][j][k])
				{
					max=B[i][j][k];
				}
			}
		}
	}
	printf("max=%d\n",max);
	///////////////////////////////////////
	system("pause");
	return 0;	
}

