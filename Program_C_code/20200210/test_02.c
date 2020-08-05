#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int i,j;
	int A=15;
	int B=16;
	int *piA,*piB;
	
	piA = &A;
	piB = &B;
	
	printf("%d\n",*piA);
	printf("%d\n",*piB);
	printf("piA x piB = %d\n",((*piA)*(*piB)));
	
	system("pause");
	return 0;
}

