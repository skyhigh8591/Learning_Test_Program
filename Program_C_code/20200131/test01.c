#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int z,y,i;
	float  x;
	y = 0;
	i = 5;
	while(i<21)
	{		
		z= i + z;
		y++;
		i++;	
	}
	x = (float)z / (float)y;	
	printf("������ = %.2f\n",x);
	printf("�`�M = %d\n",z);
	system("pause");
	return 0;




}

