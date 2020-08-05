#include<stdlib.h>
#include<stdio.h>
#define SQUARE(x) (x)*(x)

int main(void)
{
	int n;
	printf("Please input an integer:");
	scanf("%d",&n);
	printf("%dx%d=%d\n",n+1,n+1,SQUARE((n)+1));
	///////////////////////////////////////
	system("pause");
	return 0;
	
	
	
	
	
	
	
}

