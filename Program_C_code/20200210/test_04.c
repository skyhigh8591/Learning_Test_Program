#include<stdio.h>
#include<stdlib.h>

void *square(int*); 
int main(void)
{
	int arr[5]={34,76,33,42,76};
	square(arr);
	
	system("pause");
	return 0;
}
void *square(int *arr)
{
	int i,*max;

	for(i=0;i<5;i++)
	{
		printf("лe%d",*(arr+i));
		max=(*(arr+i))+(10);
		printf("	лс%d\n",max);
	}

}

