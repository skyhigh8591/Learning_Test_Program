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
		
			i++;
			break;
		}
		printf("Please input the score%d:",i);
		scanf("%d",&score[i]);
	}while(score[i++]>0);
	num=i-1;
	for(i=0;i<num;i++)
	{
		printf("%d\n",score[i]);
		sum=sum+score[i];
	}
	printf("Á`©M %4.2f\n",sum);
}
