#include<stdio.h>
#include<stdlib.h>
#define SIZE 3

float CUBIC(float,float);
int main(void)
{
	float x = SIZE,y=5,z=2.4,c;
	c=CUBIC(y,x);
	printf("5^3=%f\n",c);
	
	c=CUBIC(z,x);
	printf("2.4^3=%f\n",c);
	
	system("pause");
	return 0;
}

float CUBIC(float n,float m)
{
	if(m>0)
	{
		return n*CUBIC(n,m-1); // 4*
	}
	else
	{
		return 1;
	}
}
