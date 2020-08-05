#include<stdlib.h>
#include<stdio.h>
#define PASSWD 1234

int main(void)
{
	int i;
	int score [5];
	score[0] = 55;
	score[1] = 66;
	score[3] = 65;
	score[2] = 98;
	score[4] = 74;
	
	for(i=0;i<5;i++)
	{
		printf("scpre[%d]=%d\n",i,score[i]);
	}	
	///////////////////////////////////////
	system("pause");
	return 0;	
}

