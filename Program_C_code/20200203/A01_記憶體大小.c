#include<stdio.h>
#include<stdlib.h>

int main(void)
{
	int a=5,b=10;
	double c=6.28;
	printf("a=%4d,sizeof(a)=%d,address: %d\n",a,sizeof(a),&a);
	printf("b=%4d,sizeof(b)=%d,address: %d\n",b,sizeof(b),&b);
	printf("c=%4.2f,sizeof(c)=%d,address: %d\n",c,sizeof(c),&c);
	
	system("pause");
	return 0;
}
