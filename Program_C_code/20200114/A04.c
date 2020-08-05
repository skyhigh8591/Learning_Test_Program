#include<stdio.h>
#include<stdlib.h>
int main(void)
{

	int a=3,b=5,c=6,d=7;
	
	
	
	printf("befoer calculation: a=%d,b=%d\n",a,b);
	a+=b;
	printf("calculation: a=%d,b=%d\n",a,b);
	printf("befoer calculation: c=%d,d=%d\n",c,d);
	c*=d;
	printf("calculation: c=%d,d=%d\n",c,d);


	system("pause");
	return 0;
	
}
