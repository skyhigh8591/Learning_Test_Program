#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int value;
	int i = 10 , j = 20 , k =30;
	printf("Please input three value:");
	value = scanf("%d %d %d" , &i ,&j ,&k);
	printf("\n value is %d.\n",value);
	
	printf("  i= %d\n",i);
	printf("  j= %d\n",j);
	printf("  k= %d\n",k);
	
	system("pause");
	return 0;




}

