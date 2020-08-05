#include<stdlib.h>
#include<stdio.h>
#define LEN 9

int main(void)
{
	int i,j;
	int table[LEN][LEN];
	for(i=0;i<LEN;i++)
	{
		for(j=0;j<LEN;j++)
		{
			table[i][j]=(i+1)*(j+1); 
		}
	}
	for(i=0;i<LEN;i++)
	{
		for(j=0;j<LEN;j++)
		{
			printf("%dx%d=%2d ",(i+1),(j+1),table[i][j]);
		}
		printf("\n");	
	}
	
	///////////////////////////////////////
	system("pause");
	return 0;	
}

