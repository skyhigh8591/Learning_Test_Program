#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	char str[15]="This is a pen.";
	char str1[15],str2[15];
	char str3[30]="Hi! ";
	printf("str: \"%s\"\n",str);
	printf("str length: %d\n",strlen(str));
	strcpy(str1,"This is a book.");//將字串複製放入陣列中 
	strcpy(str2,str);
	printf("str1: \"%s\"\n",str1);
	printf("str2: \"%s\"\n",str2);// \" 表示 " 
	strcat(str3,str1);
	printf("str3: \"%s\"\n",str3);
	if(strcmp(str1,str2)>0)//比較兩個陣列大小 
	{
		printf("str1\n");
	}
	else
	{
		printf("str2\n");
	}
	
	system("pause");
	return 0;
}

