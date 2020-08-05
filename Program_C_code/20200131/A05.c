#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str1[]="xyz";
	char str2[]="abcdef";
	printf("str1: %s\n", str1);
	
	strcat(str1,str2);
	printf("str1: %s\n",str1);
	
	strncat(str1,str2,2);
	printf("str1: %s\n",str1);
	
	
	system("pause");
	return 0;
}
