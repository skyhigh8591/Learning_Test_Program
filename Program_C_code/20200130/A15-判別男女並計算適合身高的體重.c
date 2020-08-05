#include<stdio.h>
#include<stdlib.h>
float sweight(int,int);

int main(void)
{
	int sex,height;
	float weight;
	printf("Gender (0)Female (1)Male ");
	scanf("%d",&sex);
	fflush(stdin);
	printf("Please enter height (cm): ");
	scanf("%d",&height);
	fflush(stdin);
	weight=sweight(height,sex);	
	system("pause");
	printf("Your ideal body weight is %4.1f Kg\n",weight);
	
	
	
	
	
	return 0;		
}

float sweight(int h ,int s)
{
	float ret;
	if(s==0)
	{
		ret=(h-70)*0.6;
	}
	else
	{
		ret=(h-80)*0.7;
	}
	return ret;
}

