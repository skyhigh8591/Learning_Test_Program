#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,j;
	int A[2][3]={{3,2,4},{6,1,5}};
	int B[2][3]={{2,-1,3},{3,-4,-2}};
	int C[2][3];
	int *piA,*piB,*piC;
	
	for(i=0;i<2;i++)
	{
		piA=A[i];
		piB=B[i];
		piC=C[i];
		for(j=0;j<3;j++)
		{
			*(piC+j)=*(piA+j)+*(piB+j);
		}
	}
	printf("A+B=\n");
	for(i=0;i<2;i++)
	{
		piC=C[i];
		for(j=0;j<3;j++)
		{
			printf("%3d",*(piC+j));
		}
		printf("\n");
	}
	system("pause");
	return 0;
}

