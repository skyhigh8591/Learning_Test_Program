#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int score;
	
	printf("Please input a score:");
	scanf("%d",&score);
	
	if(score<60)
	{
		if(score>=50)
		{		
			printf("make up exams!\n");	
		}
		else
		{
			printf("Fail!\n");
		}
	}
	else
		{
			printf("Pass\n");
		}

	system("pause");
	return 0;
	
}
