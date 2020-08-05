#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
void show(int arr[]);

int main(void)
{
	int CC[SIZE]={5,6,7,8};
	printf("The contents of the array: ");
	show(CC);
	system("pause");
	return 0;
}

void show(int arr[])
{
	int i;
	for(i=0;i<SIZE;i++)
	{
		printf("%d " ,arr[i]);
	}
	printf("\n");
}


