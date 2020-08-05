#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	unsigned short int x,y,a,b,c,d;
	x=0x00AA;
	y=0x5500;
	a=(x<<8)+(y>>8);
	printf("a=%x\n",a);
	b=(x<<4)+(y>>8);
	printf("b=%x\n",b);
	c=(x<<4)+(y>>9);
	printf("c=%x\n",c);
	d=(x<<9)+(y>>8);
	printf("d=%x\n",d);
	system("pause");
	return 0;
}
