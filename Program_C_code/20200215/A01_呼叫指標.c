#include<stdio.h>
#include<stdlib.h>
int main(void)
{
	char name[20];
	char *ptr = " How are you";
	printf("What's your name?'");
	gets(name);
	printf("Hi, %s",name);
	puts(ptr);
	printf("Hi, %s",name);
	puts(ptr+4);
	system("pause");
	return 0;
}
