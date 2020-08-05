#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	unsigned char ch=53;
	unsigned char ix=5;
	ch=ch<<1;
	printf("ch=%d\n",ch);
	ch=ch<<1;
	printf("ch=%d\n",ch);
	ch=ch<<1;
	printf("ch=%d\n",ch);
	ch=ch>>1;
	printf("ch=%d\n",ch);
	ch=ch>>1;
	printf("ch=%d\n",ch);
	ix=ix<<5;
	printf("ix=%x\n",ix);//16¶i¦ì 
	system("pause");
	return 0;
}
