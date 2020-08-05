#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int *maxumum(int*); 
int main(void)
{
	int a[SIZE]={3,1,7,2,6};
	int i,*ptr;
	printf("array a=");
	for(i=0;i<SIZE;i++)
	{
		printf("%d ",a[i]);
	}
	ptr=maxumum(a);
	
	printf("\maxumum=%d\n",*ptr);
	system("pause");
	return 0;
}
int *maxumum(int *arr)
{
	int i,*max;
	max=arr;
	for(i=0;i<SIZE;i++)
	{
		if(*max<*(arr+i))
		{
			max=arr+i;
		}
	}
	return max;
}

