#include<stdlib.h>
#include<stdio.h>
#define PASSWD 1234

int main(void)
{
	int B[5]={55,77,49,17,68};
	int i, min , max;
	min=B[0];
	max=B[0];
	
	for(i=0;i<=5;i++)
	{
		if(B[i]>max)
		{
			max = B[i];
		}
		if(B[i]<min)
		{
			min=B[i];
		}
		
	}
	printf("The maximun value of the array element: %d\n",max);
	printf("The minimun value of the array element: %d\n",min);
	

	///////////////////////////////////////
	system("pause");
	return 0;	
}

