#include<stdio.h>
#include<stdlib.h>
#define ROW 2
#define COL 3 

int main(void)
{
	char ch='c';
	char str1[]="c";
	char str2[]="We are family";
	
	printf("ch:%4dbyte\n",sizeof(ch));
	printf("str1:%2dbyte\n",sizeof(str1));
	printf("str2:%2dbyte\n",sizeof(str2));

	
	system("pause");
	return 0;		
}

