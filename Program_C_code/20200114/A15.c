#include <stdio.h>
#include <stdlib.h>

int main(void)

{
	int i,j,n=7;
	for (i=1;i<=n;i++)
	{
		for (j=1;j<=i;j++)
			printf("*");
		printf("\n");	
	}
	
//	int k=1;
//	printf("%d\n",k++);
//	printf("%d\n",k);
	
	system("pause");
	return 0;
}
