#include<stdio.h>
#include<stdlib.h>
#define ROW 2
#define COL 3 

int main(void)
{
	char str1[15];
	str1[0]='H';		str1[1]='e';		str1[2]='l';
	str1[3]='l';		str1[4]='o';		str1[5]='!';
	str1[6]=' ';		str1[7]='w';		str1[8]='o';
	str1[9]='r';		str1[10]='l';		str1[11]='d';
	str1[12]='\n';		str1[13]='\0';	


	char str2[15]={'H','e','l','l','o','!',' ','w','o','r','l','d','\n','\0'};
	
	
	char str3[15]="Hello! world\n";
	
	
	printf("str1=%s",str1);
	printf("str2=%s",str2);
	printf("str3=%s",str3);
	
	
	system("pause");
	return 0;		
}

