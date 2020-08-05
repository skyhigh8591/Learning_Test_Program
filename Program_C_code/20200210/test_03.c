#include<stdio.h>
#include<stdlib.h>

void *square(int*); 
int main(void)
{
	int c[5]={2,4,6,8,10};
	square(c);
	
	system("pause");
	return 0;
}
void *square(int *arr)
{
	int i,*max;

	for(i=0;i<5;i++)
	{
		printf("лe%d",*(arr+i));
		max=(*(arr+i))*(*(arr+i));
		printf("	лс%d\n",max);
	}

}

