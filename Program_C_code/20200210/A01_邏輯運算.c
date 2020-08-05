#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	unsigned char cht,ch1,ch2;
	ch1=41;
	ch2=11;
	cht=ch1&ch2;
	printf("00101001 and 00001011=%2d\n",cht);
	cht=ch1|ch2;
	printf("00101001 or 00001011=%2d\n",cht);
	cht=ch1^ch2;
	printf("00101001 xor 00001011=%2d\n",cht);
	system("pause");
	return 0;
}
