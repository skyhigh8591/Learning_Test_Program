#include<stdlib.h>
#include<stdio.h>
#define MAX 5

int main(void)
{
	int score[MAX];
	int i=0;
	int num;
	float sum=0.0f;
	
	printf("Please input the score, input 0 tj end :\n");
	do
	{
		if(i==MAX)
		{
			printf("Array space has been used up!\n");
			i++;
			break;
		}
		printf("Please input the score:");
		scanf("%d",&score[i]);
	}while(score[i++]>0);
	num=i-1;
	for(i=0;i<num;i++)
	{
		sum=sum+score[i];
	}
	printf("Average score %4.2f\n",sum/num);
	

	///////////////////////////////////////
	system("pause");
	return 0;	
}

