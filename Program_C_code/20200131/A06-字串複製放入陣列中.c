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
	strcpy(str1,"This is a book.");//�N�r��ƻs��J�}�C�� 
	strcpy(str2,str);
	printf("str1: \"%s\"\n",str1);
	printf("str2: \"%s\"\n",str2);// \" ��� " 
	strcat(str3,str1);
	printf("str3: \"%s\"\n",str3);
	if(strcmp(str1,str2)>0)//�����Ӱ}�C�j�p 
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

